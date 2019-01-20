﻿// lab11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
    
}

//HINSTANCE hDLL; - ссылка (указатель) на загруженную dll, которая будет загружаться
//hDLL = LoadLibrary(L"Lab 11 Dll.dll"); - L означает использование 16-битных символов - только для x64

//FUNC2 fnc2explicit = (FUNC2)GetProcAddress(hDLL, "fnc2"); - поиск и возвращение указателья на функцию

//typedef int(CALLBACK* FUNC2)()


/* преимущества и недостатки явного и неявного подключения:
ПЛЮСЫ:
неявные:
dll грузится ОС в тот же момент, когда грузится приложение
если dll не найдено, то приложение работать не будет и аварийно завершается системой 
явное:
dll грузится в тот момент, когда этого требует разработчик
можно написать приложение, устойчивое к отказу из-за отсутствия dll
МИНУСЫ:
явное:
намного сложнее для разработчика:
требуется пользоваться сложными конструкциями языка СИПЛЮСПЛЮС
мы вынуждены пользоваться ядерными функциями windows(функции ядра)
дружественная работа с WinAPI
*/

/*1. Типы данных. Назначение. Синтаксис объявления переменных и констант. 2. Занимаемый в памяти объём. Диапазоны целых чисел (в виде степени числа 2). Инициализация переменных и констант в десятичной, шестнадцатеричной, двоичной записи. 3. Машинная запись целых чисел со знаком. Целочисленная арифметика сложения и вычитания. Дополнительный и обратный код. 
Тип данных Размер (в байтах) Диапазон 
Bool 1 0…28 
Int 4 -231…231-1 
Char 1 -27…27-1 
Long 4 -231…231-1 
Short 2 -215…215-1 
Float 4 1.17549e-38…3.40282e+38 
double 8 2.22507e-308…1.79769e+308 
Long long 8 -263…263-1 
Тип данных присваивается переменной при ее объявлении или инициализации. 
Объявление переменной: тип данных _ имя переменной. 
Объявление констант: const_тип данных_имя переменной. 
Инициализация переменной (когда объявляешь и присваиваешь значение одновременно). 
Десятичная: int i=10; 
Шестнадцатеричная: int i=0xA; 
Двоичная: ХУЙ ЕГО ЗНАТЬ ─ В int, он уже пишется в двоичном формате. 
В компьютере числа хранятся в двоичной записи. Целые числа со знаком хранятся в 8-ми, 16-ти, 32 разрядной сетке. Самый левый разряд (старший) содержит информацию о знаке числа. Если 0, то число положительное. Если 1, то ─ отрицательное. 
Положительные числа в прямом, обратном и дополнительном кодах изображаются одинаково. 
Прямой код: представление числа в двоичной системе. 
Обратный код: конвертируем прямой код (нолики меняем на единички и наоборот) 
Дополнительный код: к обратному коду добавляем 1. 
В обратном или дополнительном коде в компьютере хранятся отрицательные числа, а при выводе обратно преобразуются в десятичные. 
ЦЕЛОЧИСЛЕННАЯ АРИФМЕТИКА: 
3.3.1.1 Сложение и вычитание чисел без знака Сложение и вычитание беззнаковых чисел происходит по обычным для позиционных систем счисления алгоритмам. Примеры (для k =3): 0012 +1002 = 1012; 1012 – 0102 = 0112. Ситуации, когда уменьшаемое меньше вычитаемого или когда результат суммы не умещается в k разрядов, считаются ошибочными и должны отслеживаться устройством компьютера. Реакция на такие ошибки может быть различной в разных типах компьютеров. 3.3.1.2 Сложение и вычитание чисел со знаком в обратном коде Сложение в обратном коде происходит следующим образом: по обычному алгоритму складываются все разряды, включая знаковый. Результат такого сложения для k-разрядных наборов имеет длину k +1 (самый левый разряд результата равен единице, если был перенос при сложении старших разрядов операндов, иначе – нулю). Значение левого k +1-го разряда добавляется к младшему разряду результата. Получаем k-разрядный набор, который и будет суммой двух чисел в обратном коде. Пример (k =3): +310 +(–110 ) = 0112+ 1102 = 1 0012 B 0012 +1 = 0102 = +210. Вычитание чисел в обратном коде x – y сводится к сложению x+ (–y). 3.3.1.3 Сложение и вычитание чисел со знаком в дополнительном коде В дополнительном коде сложение происходит так: по обычному алгоритму складываются все разряды, включая знаковый; единица переноса в k +1-й разряд отбрасывается (т.е. сложение по модулю 2k ). Пример (k =3): +310 +(–110) = 0112+ 1112 = 10102 B 0102 = +210. При вычитании тоже действует обычный алгоритм, причем если уменьшаемое меньше вычитаемого, к двоичному коду уменьшаемого слева приписывается единица -6- (т.е. добавляется 2k ) и только после этого производится вычитание (такой способ называется вычитание по модулю 2k ). Пример (k =3): 110 –3 10 = 0012 – 0112 B 10012 – 0112 = 1102 = –210. 

2. Массивы. Назначение. Синтаксис объявления одномерных и многомерных массивов, и синтаксис доступа к элементу. Схема хранения одномерного и 
двумерного массива неизменной длины в оперативной памяти. Инициализация массива целиком одним числом и инициализация отдельных элементов массива. Тип, который имеет имя массива (без скобок и индекса). Доступ к элементу массива через указатель и смещение. 
Массив - блок из нескольких однотипных данных. 
задавать массивом удобно 
1. вектора и матрицы 
2. множество точек из 3D и 2D 
3. просто какой-либо числовой файл 
4. строку - массив символов 
5. видеобуфер (двумерный массив, соответствующий пикселам экрана) 
Синтаксис объявления одномерных массивов: 
тип_данных имя_массива [размер] 
Синтаксис объявления многомерных массивов: 
тип_данных имя_массива [размер1] [размер2] [размер3]; 
обращение к элементам массива: имя_массива [индекс] 
Схема хранения одномерного и двумерного массива неизменной длины в оперативной памяти. 
Элементы массива размещаются в памяти последовательно, друг за другом. Каждый элемент массива занимает столько памяти, сколько отводится под переменную, тип которой указан при описании массива. 
В двумерном массиве под каждый элемент выделяется 2 ячейки памяти. Размещение в памяти осуществляется «снизу вверх». Элементы размещаются в порядке изменения индекса, что соответствует схеме вложенных циклов: сначала размещается первая строка, затем вторая, третья... Внутри строки по порядку идут элементы: первый, второй и т.д. 
Инициализация массива целиком одним числом: 
тип_данных имя_массива [размер]={значение_для_всех} 
инициализация отдельных элементов массива: 
тип_данных имя_массива [размер]= {значение1, значение2, значение3} 
тип_данных имя_массива [размер1] [размер2] [размер3]== 
{a11, a12, a13} 
{a1, a22, a23} 
{a31, a32, a33} 
массивы в c++ нумеруются с нуля до (длина -1) 
Тип, который имеет имя массива (без скобок и индекса). 
std::array — это фиксированный массив, который не распадается в указатель при передаче в функцию. std::array определяется в заголовочном файле <array>, внутри пространства имен std. 
Объявление такого массива: std::array<тип_данных, кол-во элементов> имя массива (std::array<int, 4> t) 
Доступ к элементу массива через указатель и смещение. 
фрагмент программы: 
char str[80], *p1; 
p1 = str; 
Здесь p1 указывает на первый элемент массива str. Обратиться к пятому элементу массива str можно с помощью любого из двух выражений: 
str[4] 
* (p1+4) 

3. Операторы цикла (3 разновидности) и условного перехода (2 разновидности). Синтаксис операторов. Операторы перехода на следующий цикл и прерывания цикла. Тернарный оператор. Нестандартные варианты синтаксиса for и while 
Операторы цикла 
Цикл с предусловием (while) 
while ( выражение ) оператор Выражение определяет условие повторения тела цикла, представленного простым или составным оператором. Выполнение цикла начинается с вычисления выражения. Если оно истинно (не равно false), выполняется оператор цикла. Если при первой проверке выражение равно false, цикл не выполнится ни разу. Тип выражения должен быть арифметическим или приводимым к нему. Выражение вычисляется перед каждой 
итерацией цикла. Когда выражение оказывается ложным, управление передается следующему после цикла оператору. Тело цикла может состоять не из одного оператора, а представлять собой блок. Пример (программа находит все делители целого положительного числа): int num; cout <<RUS( "\nВведите число : "); cin>> num; int div = 2; // кандидат на делитель while (div <= num) {if (!(num % div))cout << div <<"\n"; div++;} Цикл с постусловием (do … while) do оператор while (выражение) Сначала выполняется оператор или блок, составляющий тело цикла, а затем вычисляется выражение. Если оно истинно (не равно false), тело цикла выполняется еще раз. Цикл завершается, когда выражение станет равным false или в теле цикла будет выполнен какой-либо оператор передачи управления. Тип выражения должен быть арифметическим или приводимым к нему. Пример (программа осуществляет проверку ввода): char answer; do{cout << RUS("\nКупи слоника! "); cin >> answer; } while (answer != 'y'); Цикл с параметром for for ( инициализация; выражение; модификации) оператор; Инициализация используется для объявления и присвоения начальных значений величинам, используемым в цикле. В этой части можно записать не-сколько операторов, разделенных запятой (операцией «последовательное выполнение»), например, так: for (int i = 0, j = 2; ... или int k, m: for (k = 1, m = 0; ... 
Операторы условного перехода 
Условный оператор if 
Для организации вычислений в зависимости от какого-либо условия в C++ предусмотрен условный оператор if, который в общем виде записывается следующим образом: 
if (условие) оператор_1; else оператор_2; 
Здесь условие — это логическое выражение, переменная или константа. 
Работает условный оператор следующем образом. Сначала вычисляется значения выражения, записанного в виде условия. Если оно имеет значение истина (true), выполняется оператор_1. В противном случае (значение ложное (false) ) оператор_2. 
Если в задаче требуется, чтобы в зависимости от значения условия выполнялся не один оператор, а несколько, их необходимо заключить в фигурные скобки, как составной оператор. 
if (условие) { оператор_1; оператор_2; … } 
else { оператор_1; оператор_2; … } 
Альтернативная ветвь else в условном операторе может отсутствовать, если в ней нет необходимости. 
Он необходим в тех случаях, когда в зависимости от значений переменной надо выполнить те или иные операторы: 
switch (выражение) { case значение_1: операторы_1; break; case значение_2: операторы_2; break; … case значение_n: операторы_n; break; default: операторы; break; } 
Оператор работает следующем образом. Вычисляется значение выражения. Затем выполняются операторы, помеченные значением, совпадающим со значением выражения. То есть если, выражение принимает значение_1, то 
выполняются операторы_1 и т.д.. Если выражение не принимает ни одного из значений, то выполняются операторы, расположенные после слова default. 

Оператор break необходим для того, чтобы осуществить выход из оператора switch. Если он не указан, то будут выполняться следующие операторы из списка, несмотря на то, что значение, которым они помечены, не совпадает со значением выражения. 

Синтаксис операторов 
* Пустой оператор – ; 
Пустой оператор – это оператор, состоящий только из точки с запятой. Он может появиться в любом месте программы, где по синтаксису требуется оператор. Выполнение пустого оператора не меняет состояния программы. 
* Составной оператор – {...} 
Действие составного оператора состоит в последовательном выполнении содержащихся в нем операторов, за исключением тех случаев, когда какой-либо оператор явно передает управление в другое место программы. 
* Оператор обработки исключений 
* try { <операторы> } 
* catch (<объявление исключения>) { <операторы> } 

1. Операторы перехода на следующий цикл и прерывания цикла. Тернарный оператор. + 
В теле любого цикла можно использовать операторы прерывания цикла - break и продолжения цикла - continue. 

Оператор break позволяет выйти из цикла, не завершая его. 
Оператор continue позволяет пропустить часть операторов тела цикла и начать новую итерацию. 

Пример использования оператора continue: 
for (int count=0; count < 20; ++count) 
{ 
// если число делится нацело на 4, то пропускаем весь код в этой итерации после continue 
if ((count % 4) == 0) 
continue; // пропускаем всё и переходим в конец тела цикла 
// Если число не делится нацело на 4, выполнение кода продолжается 
cout << count << endl; 
// Точка выполнение после оператора continue перемещается сюда 
} 

Пример использования оператора break: 

for (int count = 0; count <= 10; count++) // начало цикла for 
{ 
if ( count == 6) // 
break; // выход из цикла for 
cout << "2^" << count << " = " << pow(2.0,count) << endl; // печать степени двойки 
} 

Тернарный оператор. 

Он используется обычно в тех случаях, если условие и код, который надо выполнить, в результате проверки условия, очень простые. К примеру, спросить у пользователя хочет он продолжить работать в программе или же хочет выйти из неё. Синтаксис такой: 

"условие" ? "выражение 1" : "выражение 2"; 

Вначале надо записать необходимое нам условие и за ним поставить знак вопроса ? . Далее, в этой же строке, после знака вопроса пишем первую простую команду (код), которая будет выполняться, если условие вернет истину (true). После этой команды ставим двоеточие : и пишем вторую команду (код). Эта вторая команда после двоеточия, выполнится только в том случае, если условие возвращает ложь (false). 

Пример использования тернарного оператора: 
Допустим пользователь снимает деньги в банкомате. Он провел эту операцию и на экране должен появиться вопрос: “Вы хотите выполнить другую операцию?” Пользователю остается сделать выбор (да или нет) и нажать соответствующую кнопку. Организуем этот выбор в следующей программе: 

bool variable = true; 

cout << "Выполнение каких-то транзакций по счету карты...\n"; 
cout << "Вы хотите выполнить другую операцию (1 - да, 0 - нет)? "; 
cin >> variable; 

variable == 1 ? cout << "Выберите операцию!\n..........\n\n" : cout << "До свидания! Не забудьте взять чек!\n\n"; 

2. Нестандартные варианты синтаксиса for и while. + 
Нестандартные возможности цикла for: 
1) Применение нескольких переменных управления циклом. 

int a, b; 
for (a=0, b=9; a < 10; ++a, --b) 
cout << a << " " << b << endl; 

2) Отсутствие части цикла. 

int count=0; 
for ( ; count < 10; ) 
{ 
cout << count << " "; 
++count; 
} 

3) Бесконечный цикл. 

int main() { 
int i = 0; 
for (;;){ 
i++; 
cout << i; 
} 
return 0; 
} 

Нестандартные возможности цикла while: 1) Бесконечный цикл. 
int main() { 
int i = 0; 
while (true){ 
i++; 
cout << i; 
} 
return 0; 
} 
4. Функция. Назначение. Синтаксис объявления, определения и вызова. Принцип работы функции. Передача параметров по ссылке и по значению. Стек, пролог и эпилог функции. Адрес возврата. 

5. Указатель. Назначение. Синтаксис объявления указателя и доступа к данным, на которые ссылается указатель. Данные в динамической памяти. Синтаксис объявления и удаления. Объявление и удаление одномерных и многомерных массивов в динамической памяти. Сравнение особенностей хранения массивов статической длины и динамических массивов в оперативной памяти. 
Указатель –переменная, хранящая адрес другой переменной в памяти. 
Назначение. Все указатели всегда одной и той же разрядности (размера). Каким бы ни был огромным тип данных (строка, объект, массив) указатель на него всегда будет занимать 4/8 байт, что и является основным преимуществом указателей. 
Синтаксис объявления указателя и доступа к данным, на которые ссылается указатель. 
тип_данных * имя_указателя (int * ptr_a) 
int *ptr_int = &a; 
Оператор амперсенд & - оператор получения адреса. 
Данные в динамической памяти. Динамическое выделение памяти необходимо для эффективного использования памяти компьютера. Например, мы написали какую-то программку, которая обрабатывает массив. При написании данной программы необходимо было объявить массив, то есть задать ему фиксированный размер (к примеру, от 0 до 100 элементов). Тогда данная программа будет не универсальной, ведь может обрабатывать массив размером не более 100 элементов. А если нам понадобятся всего 20 элементов, но в памяти выделится место под 100 элементов, ведь объявление массива было статическим, а такое использование памяти крайне неэффективно. 
Преимущества: 
1) доступно гораздо больше памяти, нежели в стеке (стек вызовов отслеживает все активные функции) 
2) размеры массивов и структур данных можно определять и менять во время работы приложения 
Особенность: для приложения, предназначенного для длительной работы, во избежание переполнения памяти созданные переменные и блоки памяти после использования должны быть освобождены с помощью оператора delete: delete имя_переменной. 
Синтаксис объявления и удаления. Для использования свободной памяти ОС (heap - "куча" - отслеживает память, используемую для динамического выделения.) 
объявляются динамические переменные по синтаксису: 
указатель на тип имя переменной =new тип или тип*имя_переменной = new тип 
удаление: delete имя_переменной 
Объявление и удаление одномерных и многомерных массивов в динамической памяти. 
Одномерные: 
пара операторов new/delete - это одно из нововведений С++ относительно С 
В динамической памяти могут выделяться только одномерные массивы 
тип * имя_указатель = new тип [длина]; 
удаляются одномерные массивы с помощью записи 
delete[] имя_указателя. (память возвращается обратно в кучу и затем может быть переназначена) 
Многомерные: 
для выделения двумерного массива сначала создаётся одномерный массив, содержащий указатели на другие массивы (строки) 
МОЖЕМ ЗАДАВАТЬ РАЗМЕРНОСТИ ПЕРЕМЕННЫМИ 
int ** dynamic2Darray = new int *[l1]; 
затем выделяется блок памяти под каждую строку и указатель на неё возвращается в созданный массив указателей 
for (int i = 0; i < l1; i++) 
{ 
dynamic2Darray[i] = new int[l2]; 
/dynamic2Darray[i] имеет тип (int*)/ 
for (int j = 0; j < l2; j++) 
{ dynamic2Darray[i][j] = j; } 
} 
Сравнение особенностей хранения массивов статической длины и динамических массивов в оперативной памяти. 
многомерные массивы фиксированной длины в стековой памяти чаще всего размещаются сплошным блоком 
динамические - нет (где ОС выделила место под очередную строку - там она и будет находиться, и между строками будет неизвестно что) 

6. Классы и объекты. Назначение. Синтаксис объявления, определения, доступа к свойствам и вызова методов. Модификаторы доступа. Конструктор и деструктор. Наследование. Назначение. Синтаксис. Множественное наследование. Указатель this и каким образом он передаётся в методы классов. 
7. Библиотеки. Назначение. Примеры библиотек с открытым кодом. Типы связывания. Преимущества и недостатки различных типов. Статическое связывание. Неявное связывание динамических библиотек. Явное связывание динамических библиотек. 
8. Перегрузка функций и методов. Назначение. Синтаксис перегрузки. Привести примеры. Принцип работы перегруженных функций и методов. Перегрузка унарных и бинарных операторов. Привести примеры. 
Перегрузка функций и методов 
Перегрузка (overloading) - объявление нескольких функций, а также методов классов и операторов, которые тоже являются функциями с одинаковыми именами, но с разным набором аргументов. 
Назначение. 
Перегрузка функций и методов используется, когда нужно сделать одно и то же действие с разными типами данных. 
Синтаксис перегрузки: 
Единственное условие – одинаковые имена. 
Привести примеры 
Перегрузка функции (было int стало double): 
int max(int num1, int num2) 
{ 
if (num1 > num2) 
return num1; 
return num2; 
} 
double max(double num1, double num2) 
{ 
if (num1 > num2) 
return num1; 
return num2; 
} 
Перегрузка метода: 
Double P (double a, double b, double c) 
{ 
return a+b+c; /P треугольника/ 
} Double P (double a, double b, double c, double d) 
{ 
return a+b+c+d /P четырехугольника/ 
} 
Принцип работы перегруженных функций и методов 
Перегружаемые функции имеют одинаковое имя, но разное количество или типы аргументов. При перегрузке вопрос о том, какую из функций вызвать, решается по списку её аргументов. 
Перегруженная функция фактически представляет собой несколько разных функций, и выбор подходящей происходит на этапе компиляции. Компилятор работает не с именами функций, а их внутренними представлениями, которые существенно отличаются от используемых в программе. Эти имена содержат в себе скрытое описание типов аргументов. Компилятор не различает функции по типу возвращаемого значения. Поэтому для компилятора функции с различным списком аргументов – это разные функции, а с 
одинаковым списком аргументов, но с разными типами возвращаемого значения - одинаковые. Для корректной работы программ последнего следует избегать. 
Перегрузка унарных и бинарных операторов 
Унарные и бинарные операторы перегружаются по-разному. 
унарные - в самом классе (получается новый метод класса) 
бинарные - как отдельная функция 
бинарные операторы прописываются вне класса, так как результат необязательно записывается в один из операндов, а может записываться в некий третий объект 
в унарных операторах результат записывается в тот же самый объект, для которого вызван оператор, поэтому унарный стоит отнести к методам класса. 
Привести примеры: 
Унарные: const Integer& operator++(Integer& i) { i.value++; return i; } const Integer& operator--(Integer& i) { i.value--; return i; } Бинарные: const Integer operator+(const Integer& left, const Integer& right) 
{ return Integer(left.value + right.value); } Integer& operator+=(Integer& left, const Integer& right) 
{ left.value += right.value; return left; } 
9. Шаблон. Назначение. Синтаксис объявления и использования шаблонов функций и классов. Примеры. Принцип работы шаблонов. Вариации синтаксиса объявления и использования шаблонов. 
10. Классификация языков. Преимущества и недостатки. Язык C и C++. Краткая история. 
11. Строки в C и C++. Функции и методы работы со строками. 
Чтобы иметь возможность использовать строки в C++, сначала нужно подключить директиву #include <string>. Как только это будет сделано, мы сможем определять переменные типа std::string. 
Функции и методы: 
1) std::getline() - чтобы извлечь полную строку ввода. Она принимает два параметра: первый – std::cin, второй — переменная string: 
std::getline(std::cin, string) 
2) имя строки.length() - длина строки; 
3) имя строки.size() – размер строки; 
4) имя строки.empty() – вернёт true, если строка пустая; 
5) имя строки.strcpy() - копирует содержимое одной строки в другую (в С) 
6) имя строки.strcpy_s - копирует содержимое одной строки в другую, добавлен параметр для определения размера места назначения; 
7) имя строки.strcat() — добавляет одну строку к другой (опасно); 
8) имя строки.strncat() — добавляет одну строку к другой (с проверкой размера места назначения); 
9) имя строки.strcmp() — сравнивает две строки (возвращает 0, если они равны); 
10) имя строки.strncmp() — сравнивает две строки до определенного количества символов (возвращает 0, если они равны).*/
