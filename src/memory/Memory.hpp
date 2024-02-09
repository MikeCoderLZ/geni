# pragma once

#include <cstdlib>

namespace geni::mem {

  using Byte = char;
  using Size = std::size_t;

  template<mem::Size n>
  class Bytes {
    public:
      Bytes() : mFirst{'\0'}, mRest{'\0'} {}
      explicit
      Bytes( Byte fill ) : mFirst{fill}, mRest{fill} {}

      operator bool() const {return true;}

      template< typename Function >
      void each( Function&& f )
      { std::invoke(f,first()); rest().each(f); }

      auto first() -> Byte& { return mFirst; }
      auto rest() -> Bytes<n-1>& { return mRest; }

    private:
      Byte mFirst;
      Bytes<n-1> mRest;
  };

  template<>
  class Bytes<0> {
    public:
      operator bool() const {return false;}
      template< typename Function >
      void each( Function&& f ) { return; }
  };

  template<>
  class Bytes<1> {
    public:
      Bytes() : mFirst{'\0'} {}
      explicit
      Bytes( Byte fill ) : mFirst{fill} {}
      template< typename Function >
      void each( Function&& f )
      { std::invoke(f,first()); }
      operator bool() const {return true;}
      Byte first() const { return mFirst; }
      auto rest() -> Bytes<0>& {return mRest;}
    private:
      Byte mFirst;
      Bytes<0> mRest;
  };

  template<typename Type>
  constexpr Type* nullInstance{ static_cast<Type*>(nullptr) };

  template<typename Type, typename MemberType, MemberType (Type::* MemberPtr)>
  constexpr Size offset{ reinterpret_cast<size_t>(nullInstance<Type>()->*MemberPtr) };

  template<typename Type, typename Member>
  inline
  auto thisFrom( Member& member, Member (Type::* memberPtr) ) -> Type&
  { return *reinterpret_cast<Type*>(reinterpret_cast<Byte*>(&member) - offset<Type, Member, memberPtr> ); }

}
