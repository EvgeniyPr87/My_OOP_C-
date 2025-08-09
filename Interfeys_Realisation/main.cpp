#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// фиктивные функции (заглушки):
void sendEmail(const string& message, const string& recipient) {
	//имитация отправки email
}
void sendSMS(const string& message, const string& recipient) {
	//имитация отправки SMS
}
void sendPushNotification(const string& message, const string& recipient) {
	//имитация отправки Push
}

//	Необходимо разработать систему уведомлений,
//которая может отправлять сообщения различным типам получателей
//(например, по электронной почте, SMS, через push-уведомления в мобильном приложении).

//	Определяем интерфейс:
class INotificationChanel
{
public:
	virtual void sendMessage(const string& message,const  string& recipient)const = 0;
	
	virtual ~INotificationChanel() = default;
};

class EmailNotificationChanell :public INotificationChanel {
	
public:
	void sendMessage(const string& message, const  string& recipient)const override {
		cout << "Sending email to: " << recipient << ", message: " << message << endl;
		sendEmail(message, recipient);
	}
};

class SMSNotificationChannel :public INotificationChanel {
public:
	void sendMessage(const string& message, const  string& recipient)const override {
		cout << "Sending SMS to: " << recipient << ", message: " << message << endl;
		sendSMS(message, recipient);
	}
};

void main() {

	setlocale(LC_ALL, "");


}
