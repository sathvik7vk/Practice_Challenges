//Below program violates DIP.
//Challenge to fix it

//Problem:

// #include <iostream>
// #include <string>

// // Low-level module
// class GmailService {
// public:
//     void sendEmail(std::string message) {
//         std::cout << "Sending Gmail: " << message << std::endl;
//     }
// };

// // High-level module
// class AlertManager {
// private:
//     GmailService service; // Hard dependency on a specific class!
// public:
//     void notify(std::string message) {
//         service.sendEmail(message);
//     }
// };

// int main() {
//     AlertManager admin;
//     admin.notify("System Overheating!");
//     return 0;
// }

//Solution
#include <iostream>
#include <string>
#include <memory>


class IAlertManager
{
    public:
    virtual void SendAlert(std::string message) = 0;
};

class GmailService:public IAlertManager
{
    public:
    void SendAlert(std::string message)
    {
        std::cout<<"Sending mail : " <<message<<std::endl;
    }

};

class SMSService:public IAlertManager
{
    public:
    void SendAlert(std::string message)
    {
        std::cout<<"Sending sms : " <<message<<std::endl;
    }

};

class AlertManager
{
    private:
    std::unique_ptr<IAlertManager> service;

    public:
    AlertManager(std::unique_ptr<IAlertManager>&& iService){service = std::move(iService);}
    ~AlertManager(){}

    void notify(std::string msg)
    {
        service->SendAlert(msg);
    }

};




int main() {
    AlertManager manager (std::make_unique<GmailService>());
    manager.notify("System overheating");
    return 0;
}
