#include <iostream>
#include <stdexcept>

using namespace std;
enum messageLogType {ERROR, WARNING, INFO};

class console_logger{
public:
    void log(messageLogType type, string message){
        if (message.empty()){
            throw invalid_argument("Message is empty");
        }
        switch(type){
            case ERROR:
                cout << "ERROR: " << message << endl;
                break;
            case WARNING:
                cout << "WARNING: " << message << endl;
                break;
            case INFO:
                cout << "INFO: " << message << endl;
                break;
        }
    }
};

int main(){
    console_logger logger;
    try
    {
        logger.log(ERROR, "This is an error message");
        logger.log(WARNING, "This is a warning message");
        logger.log(INFO, "This is an info message");
        logger.log(INFO, ""); // exeption will be thrown
    }
    
    catch(const exception& e)
    {
        cout << e.what() << '\n';
    }
    

    return 0;
}