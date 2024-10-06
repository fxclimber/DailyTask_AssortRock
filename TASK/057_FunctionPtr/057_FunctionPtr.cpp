// 강의 코드가 이해가 안되서, GPT 코드로 대체

#include <iostream>

// Base 클래스 정의
struct Base {
    // 가상 함수 테이블에 연결될 가상 함수
    virtual void GetAtt() {
        std::cout << "Base::GetAtt 호출" << std::endl;
    }

    virtual void Render() {
        std::cout << "Base::Render 호출" << std::endl;
    }
};

// Derived 클래스 정의 (Base로부터 상속)
struct Derived : public Base {
    // Base 클래스의 가상 함수를 오버라이드(override)
    void GetAtt() override {
        std::cout << "Derived::GetAtt 호출" << std::endl;
    }

    void Render() override {
        std::cout << "Derived::Render 호출" << std::endl;
    }
};

int main() {
    // 다형성의 핵심: 부모 클래스 포인터가 자식 클래스 객체를 가리킬 때
    Base* basePtr = new Derived();  // 부모 클래스 포인터가 자식 클래스 객체를 가리킴

    // 부모 클래스의 포인터를 통해 가상 함수 호출
    basePtr->GetAtt();  // Derived::GetAtt 호출 (자식 클래스의 함수가 호출됨)
    basePtr->Render();  // Derived::Render 호출 (자식 클래스의 함수가 호출됨)

    // 메모리 해제
    delete basePtr;

    return 0;
}
