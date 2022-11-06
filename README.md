# mtfind

<h4>Тестовое задание</h4> 
<br>
Написать программу mtfind, производящую поиск подстроки в текстовом файле по маске с использованием
многопоточности.<br>

Маска - это строка, где "?" обозначает любой символ.<br>
<hr>
Программа принимает в качестве параметров командной строки:<br>
1. Имя текстового файла, в котором должен идти поиск (размер файла - до 1Гб).<br>
2. Маску для поиска, в кавычках. Максимальная длина маски 1000 символов.<br>
<hr>
Вывод программы должен быть в следующем формате:<br>
На первой строке - количество найденных вхождений.<br>
Далее информация о каждом вхождении, каждое на отдельной строке, через пробел: номер строки, позиция в
строке, само найденное вхождение.<br>
Порядок вывода найденных вхождений должен совпадать с их порядком в файле<br>
<hr>
Дополнения:<br>
В текстовом файле кодировка только 7-bit ASCII<br>
Поиск с учетом регистра<br>
Каждое вхождение может быть только на одной строке. Маска не может содержать символа перевода строки<br>
Найденные вхождения не должны пересекаться. Если в файле есть пересекающиеся вхождения то нужно
вывести одно из них (любое).<br>
Пробелы и разделители участвуют в поиске наравне с другими символами.<br>
Можно использовать STL, Boost, возможности С++1x.<br>
Многопоточность нужно использовать обязательно. Однопоточные решения засчитываться не будут.<br>
Серьезным плюсом будет разделение работы между потоками равномерно вне зависимости от количества строк
во входном файле.<br>
Решение представить в виде архива с исходным кодом и проектом CMake или Visual Studio (либо в виде ссылки на
онлайн Git-репозиторий). Код должен компилироваться в GCC или MSVC.<br>
