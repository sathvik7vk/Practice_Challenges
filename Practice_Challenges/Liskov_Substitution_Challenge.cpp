//Below program violates LSP
//Problem:

// #include <iostream>
// #include <vector>

// class Bird {
// public:
//     virtual ~Bird() = default;
//     virtual void fly() {
//         std::cout << "I am flying high!" << std::endl;
//     }
// };

// class Sparrow : public Bird {
//     // Works fine!
// };

// class Ostrich : public Bird {
// public:
//     void fly() override {
//         throw std::runtime_error("I can't fly! I'm too heavy!");
//     }
// };

// void makeBirdFly(Bird& b) {
//     b.fly(); // This function expects ALL birds to fly.
// }

// int main() {
//     Sparrow s;
//     Ostrich o;

//     makeBirdFly(s); // Works
//     makeBirdFly(o); // CRASHES the program! (LSP Violation)
//     return 0;
// }

//Solution
#include <iostream>
#include <vector>

class FlyingBird {
public:
    virtual ~FlyingBird() = default;
    virtual void fly() {
        std::cout << "I am flying high!" << std::endl;
    }
};


class NonFlyingBird {
public:
    virtual ~NonFlyingBird() = default;
    virtual void Run() {
        std::cout << "I can run fast!" << std::endl;
    }
};


class Sparrow : public FlyingBird {
    // Works fine!
};

class Ostrich : public NonFlyingBird {
public:
    void Run() override {
        std::cout<<"I can run"<<std::endl;
    }
};

void makeBirdFly(FlyingBird& b) {
    b.fly(); // This function expects ALL birds to fly.
}

int main() {
    Sparrow s;
    Ostrich o;

    makeBirdFly(s); // Works
    //makeBirdFly(o); // CRASHES the program! (LSP Violation)
    return 0;
}