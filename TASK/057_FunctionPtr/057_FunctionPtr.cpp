// ���� �ڵ尡 ���ذ� �ȵǼ�, GPT �ڵ�� ��ü

#include <iostream>

// Base Ŭ���� ����
struct Base {
    // ���� �Լ� ���̺� ����� ���� �Լ�
    virtual void GetAtt() {
        std::cout << "Base::GetAtt ȣ��" << std::endl;
    }

    virtual void Render() {
        std::cout << "Base::Render ȣ��" << std::endl;
    }
};

// Derived Ŭ���� ���� (Base�κ��� ���)
struct Derived : public Base {
    // Base Ŭ������ ���� �Լ��� �������̵�(override)
    void GetAtt() override {
        std::cout << "Derived::GetAtt ȣ��" << std::endl;
    }

    void Render() override {
        std::cout << "Derived::Render ȣ��" << std::endl;
    }
};

int main() {
    // �������� �ٽ�: �θ� Ŭ���� �����Ͱ� �ڽ� Ŭ���� ��ü�� ����ų ��
    Base* basePtr = new Derived();  // �θ� Ŭ���� �����Ͱ� �ڽ� Ŭ���� ��ü�� ����Ŵ

    // �θ� Ŭ������ �����͸� ���� ���� �Լ� ȣ��
    basePtr->GetAtt();  // Derived::GetAtt ȣ�� (�ڽ� Ŭ������ �Լ��� ȣ���)
    basePtr->Render();  // Derived::Render ȣ�� (�ڽ� Ŭ������ �Լ��� ȣ���)

    // �޸� ����
    delete basePtr;

    return 0;
}
