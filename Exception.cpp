#include <iostream>
#include <math.h>
#include <exception>

using namespace std;

//Шупик Карина

//202ТН

/*Функції, реалізовані в завданнях, повинні виконувати перевірку переданих
параметрів і генерувати виключення у випадку помилкових. Усі функції
реалізуються в чотирьох варіантах:
• без специфікації виключень;
• зі специфікацією throw();
• с конкретною специфікацією з відповідним стандартним виключенням;
• специфікація із власним реалізованим виключенням.
Власне виключення повинне бути реалізоване в трьох варіантах: 
    як порожній клас, як незалежний клас із полями-параметрами функції, 
    як спадкоємець від стандартного виключення з полями. Перехоплення й обробку
    виключень повинна виконувати головна функція.
*/

//6. Функція обчислює суму геометричної прогресії


    void geometricProgression1(float b, float q, float n) {
        float s = (b * (1 - pow(q, n))) / (1 - q);
        cout << "Sum of progression`s members: " << s << endl;
    }

    void geometricProgression2(float b, float q, float n) {
        try {
            if (b == 0)
                throw 1;
            if (q == 1)
                throw 2;
            if (n < 0)
                throw 3;

            float s = (b * (1 - pow(q, n))) / (1 - q);
            cout << "Sum of progression`s members: " << s << endl;
        }
        catch (int error) {
            if (error == 1)
                cout << "First number of progressin equal to 0" << endl;//b
            if (error == 2)
                cout << "Progression denominator can`t be equal to 1" << endl;//q
            if (error == 3)
                cout << "Member number equal to 0" << endl;//n
        }
    }

    float geometricProgression3(float b, float q, float n) {
        if (b == 0)
            throw runtime_error("First number of progressin equal to 0");
        if (q == 1)
            throw runtime_error("Progression denominator can`t be equal to 1");
        if (n < 0)
            throw runtime_error("Member number equal to 0");

        float s = (b * (1 - pow(q, n))) / (1 - q);
        return s;
    }






int main()
{
    cout << "First attempt: " << endl;
    geometricProgression1(10, 1, 3);

    cout << "Second attempt: " << endl;
    geometricProgression2(10, 1, 3);

    cout << "Third attempt: " << endl;
    try {
        float result = geometricProgression3(10, 1, 3);
        cout << "Result equal to: " << result << endl;
    }
    catch (const overflow_error error) {
        cout << "Overflow error!" << error.what() << endl;
    }
    catch (const runtime_error error) {
        cout << "Runtime error!" << error.what() << endl;
    }
    catch (const exception error) {
        cout << "Exception!" << error.what() << endl;
    }
    cout << "End!" << endl;
    
}
