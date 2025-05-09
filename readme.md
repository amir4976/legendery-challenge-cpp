### numer converter --Legendary challenge

## this test is base on amazon and google interview test so it's not a easy one

### (except if you are a genius like me 😎)

so this is a test that i did for a job interview
and i said sh\*t it's not easy but it's not that hard
its just take one hour to naild it whhhhaaat!!
# hell yeh scrow gpt or any copilt i did it by my self 

so i will share it with you guy's becuse im so humble

**step 1:**
define the array like for words
but what words?  numbers in words
for ones and teens and tens

**step 2:**
create a chunkToWords function that make the chunk of the number
and convert it to words but not just 3 digits of numbers
so i use the( %= ) for passing the number to the next chunk
```
i mean if the number in the first chunk is 345
num / 100 = 3 ===> three hundred
and 345 %= 100 = 45
and 45 / 10 =4  === forty
\--- in special condition it migh be a teen number like 14 we have to set and else if to fix teen number problems and u good to go
and 45 % 10 = 5
```
and just we have to put it in ons array index -1 and we get "five"
if you have any better idea let me know


**step 3:**
create a function name numberToWords that take the number and convert it to words and return it
first thing first i check if the number is zero then return zero
i mean if the number is 0 return zero (what kind of idot would do that😂😂)
then we set a condition if number is less then 1000000 then return the chunkToWords function
that we pass the original number to devided to 1000000
and this is the funny part its return only ones and then we add a word like "million"
whhhhaaat!! yeh that is the tricky part
same thing for thousand if you want you can make it more complex but i think it's enough
so we add the return data in the result and then we return it
but before we have to make sure that the result is not empty
and if it have any space in the end we remove it (result.pop\_back()) (this shit was so god demn hard)

**step 4:**
create a function name word to number that take the number and convert it to words and return it
so first thig first we have need an object that can be litural
so i deeg a little bit and i find out the unordered\_map is the best for this case
just like types in typescript we have to specify the key and value type
once we have the type we can use it like a normal object . in cpp there is not any objects so this is an arrey
then i define two variables word and cleaned


i think i have to explain this part a little bit 
    so i use istringstream ss (str) what is this mean ? :
    its stands for (input string stream) its allowd us to read data from a string as if it were a stream of characters
    liturly its mean we can read one by one char from the string
    new you know what is {istringstream ss (str)} mean

then i define two int variable for result and current number both are zero
and i use a while loop to read the string one by one char
first we clean the string from any cama or space or any other shit and we make it a lower case
new we just play whit the result and the current number 
(i cant even explae what i writh in here i just writh it and it worked 😂😂 i was like wtf just happend 😂😂😂)


**step 5:**
last thing is to create a function that just define the type of the input
so i use a flag name isNumber (this is elon musk) that is true at the first
and i serch and find isdigit method that helped me a lot and make my code cleaner
i loop into the input and check if the char is digit or not if its not i make isNumber false and break the loop
but if isNumber is remain true then i return the numbertoword // wordTonumber function
its just in a simple word check if user enter a number or  word and return the propet function

**step 6:**
last but not least u have to create a main (obviously!!!)
i use a getline function to get the input from the user
and i run the convertNumber and display the result
and thats it

## so this it

### i hope you learn something new

## i realy enjoy doing this test and i realy hope you enjoy it too

# was a tough challenge and i did it in 1 hour and 20 minutes let me know if you can brack my reccord
