#include <iostream>
#include <string>
#include <vector>
#include "cpr/cpr.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    std::vector<cpr::Pair> payloadData;
    std::string s1, s2, address;
    cpr::Response response;
    address = "?";

   do{
        cout << "Enter command: ";
        cin >> s1;
        if(s1 == "get" || s1 == "post") break;
        cin >> s2;
        payloadData.emplace_back(s1, s2);
    }while(s1 != "get" || s1 != "post");

   if(s1 == "post"){
       response = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload(payloadData.begin(), payloadData.end()));
       cout << response.text << endl;
   }else if(s1 == "get"){
       for(int i = 0; i < payloadData.size(); i++){
           address += payloadData[i].key + "=" + payloadData[i].value + "&";
       }
       response = cpr::Get(cpr::Url("http://httpbin.org/get" + address));
       cout << response.text << endl;
   }

    return 0;
}

/*Сделайте запрос к сервису httpbin.org, отправив при этом несколько дополнительных аргументов с данными.
Все названия аргументов и их значения — строковые, и принимаются от пользователя. Пользователь
последовательно вводит их названия вместе со значениями, пока не встретится аргумент с названием
«post» или «get», что будет означать, что ввод аргументов закончен и требуется отправить их на сервер выбранным способом.

Если пользователь выбрал «post», то выполняется POST-запрос и аргументы отправляются
POST-способом (как форма). Если «get», то GET-запрос с GET-аргументами (прямо в URL).

По результатам выполнения запроса, выведите ответ сервера в стандартную консоль и
обратите внимание на поля form или args, в зависимости от типа запроса в которых должны
быть перечислены все введённые вами аргументы.



Советы и рекомендации
Согласно HTTP-стандарту, аргументы в GET-запросах перечисляются прямо в URL запроса после вопросительного знака.
Названия аргументов отделяются от их значений с помощью символа «=»), а сами аргументы разделены символами «&».

Пример аргументов, заданных в URL запроса: ?foo=first&animal=cat&bar=third
*/

