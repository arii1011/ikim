#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int get_choice();
int atomic_number();
int atomic_symbol();
int atomic_name();
int atomic_weight();
int electronic_configuration();
int atomic_period();
char atomic_block();
char atomic_property();
int atomic_group();
char atomic_class();
void display(int, char, char, char, char, char);

// Names of Elements 
char atoms[118][25] = {
    "Hydrogen", "Helium",                                                                                                                                                                                                                                                                                                                                                                                                              // there are two elements in first row 
    "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",                                                                                                                                                                                                                                                                                                                                               // there are eight elements in second 
    "Sodium", "Magnesium", "Aluminium", "Silicon", "Pottasium", "Sulphur", "Chlorine", "Argon",                                                                                                                                                                                                                                                                                                                                        // there are eight elements in third row 
    "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton",                                                                                                                                                                                                                            //  there 18 elemts in fourth row
    "Rubudium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",                                                                                                                                                                                                                     // there 18 elements in fifth row 
    "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thalium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon",                                                     // there are 32 elements in sixth row 
    "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Ensteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson", //  there are 32 elements in last row of periodic table 
};

// symbols of elements 
char at_symbols[118][3] = {
    "H", "He",
    "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
    "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu",
    "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I", "Xe",
    "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy",
    "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
    "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
    "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
    "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
    "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

//atomic weight of elements 
double at_mass[118] = {
    1.00, 4.00,
    6.94, 9.01, 10.81, 12.01, 14.00, 15.99, 18.99, 20.18,
    22.99, 24.30, 26.98, 28.08, 30.97, 32.06, 35.45, 39.95,
    39.09, 40.07, 44.95, 47.86, 50.94, 51.99, 54.93, 55.84,
    58.93, 58.69, 63.54, 65.38, 69.72, 72.63, 74.92, 78.97, 79.90, 83.79,
    85.46, 87.62, 88.90, 91.22, 92.90, 95.95, 97.00, 101.07, 102.91, 106.42, 107.87,
    112.41, 114.82, 118.71, 121.76, 127.60, 126.90, 131.29,
    132.91, 137.33, 138.91, 140.12, 140.91, 144.24, 145.00, 150.36, 151.96, 157.25, 158.93,
    162.50, 164.93, 167.26, 168.93, 173.05, 174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22,
    195.08, 196.97, 200.59, 204.38, 207.20, 208.98, 209.00, 210.00, 222.00,
    223.00, 226.00, 227.00, 232.04, 231.04, 238.03, 237.00, 244.00, 243.00, 247.00, 247.00, 251.00,
    252.00, 257.00, 258.00, 259.00, 266.00, 267.00, 268.00, 269.00, 270.00, 269.00, 278.00, 281.00,
    282.00, 285.00, 286.00, 289.00, 290.00, 293.00, 294.00, 294.00};

//electronic configuration 
char elec_config[118][30] = 
    {
    "1",  "2",
    "2,1", "2,2",  "2,4", "2,5", "2,6",   "2,7",   "2,8",   "2,8,1",
    "2,8,2","2,8,3",  "2,8,4","2,8,5",  "2,8,6",  "2,8,7",   "2,8,8",  "2,8,8,1",
    "2,8,8,2",  "2,8,9,2",   "2,8,10,2", "2,8,11,2",  "2,8,13,1", "2,8,13,2", "2,8,14,2", "2,8,15,2","2,8,16,2","2,8,18,1","2,8,18,2","2,8,18,3","2,8,18,4","2,8,18,5", "2,8,18,6","2,8,18,7",   "2,8,18,8",  "2,8,18,8,1", 
    "2,8,18,8,2",   "2,8,18,9,2",   "2,8,18,10,2",   "2,8,18,12,1",   "2,8,18,13,1",  "2,8,18,13,2",  "2,8,18,15,1",   "2,8,18,16,1",   "2,8,18,18", "2,8,18,18,1", "2,8,18,18,2",  "2,8,18,18,3",  "2,8,18,18,4", "2,8,18,18,5","2,8,18,18,6", "2,8,18,18,7", "2,8,18,18,8", "2,8,18,18,8,1",
    "2,8,18,18,8,2",  "2,8,18,18,9,2",  "2,8,18,19,9,2", "2,8,18,21,8,2",  "2,8,18,22,8,2",  "2,8,18,23,8,2",  "2,8,18,23,8,2","2,8,18,25,8,2","2,8,18,25,9,2", "2,8,18,27,8,2", "2,8,18,28,8,2","2,8,18,29,8,2",   "2,8,18,30,8,2",   "2,8,18,31,8,2",   "2,8,18,32,8,2",   "2,8,18,32,9,2", "2,8,18,32,10,2",  "2,8,18,32,11,2", "2,8,18,32,12,2", "2,8,18,32,13,2",  "2,8,18,32,14,2", "2,8,18,32,15,2",   "2,8,18,32,17,1",  "2,8,18,32,18,1", "2,8,18,32,18,2",  "2,8,18,32,18,3", "2,8,18,32,18,4", "2,8,18,32,18,5", "2,8,18,32,18,6",  "2,8,18,32,18,7",  "2,8,18,32,18,8",   "2,8,18,32,18,8,1",
    "2,8,18,32,18,8,2",   "2,8,18,32,18,9,2", "2,8,18,32,18,10,2",   "2,8,18,32,20,9,2",  "2,8,18,32,21,9,2",  "2,8,18,32,22,9,2", "2,8,18,32,24,8,2", "2,8,18,32,25,8,2","2,8,18,32,25,9,2", "2,8,18,32,27,8,2", "2,8,18,32,28,8,2","2,8,18,32,29,8,2",  "2,8,18,32,30,8,2", "2,8,18,32,31,8,2", "2,8,18,32,32,8,2", "2,8,18,32,32,8,3", "2,8,18,32,32,10,2", "2,8,18,32,32,11,2", "2,8,18,32,32,12,2", "2,8,18,32,32,13,2", "2,8,18,32,32,14,2", "2,8,18,32,32,15,2", "2,8,18,32,32,16,2", "2,8,18,32,32,17,2","2,8,18,32,32,18,2", "2,8,18,32,32,18,3", "2,8,18,32,32,18,4","2,8,18,32,32,18,5","2,8,18,32,32,18,6","2,8,18,32,32,18,7", "2,8,18,32,32,18,8"
    };
//atomic state of elements 
char atomic_state[118][10] = 
    {
    "Gas", "Gas",
    "Solid", "Solid", "Solid",
    "Solid", "Gas", "Gas", "Gas", "Gas",
    "Solid", "Solid", "Solid",
    "Solid", "Solid", "Gas", "Gas", "Gas", "Solid",
    "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid  ", "Gas  ", "Gas", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Gas", "Solid", "Solid ", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Liquid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Gas", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Solid",
    "Solid", "Solid", "Solid", "Solid", "Solid", "Solid", "Gas"
    };
//main program
int main()
{
    int i=999, choice;
    do {
        choice=get_choice();
        char ch1, ch2, ch3, ch4, ch5;
        switch (choice)
        {
        case 1:
            i = atomic_number();
            break;
        case 2:
            i = atomic_symbol();
            break;
        case 3:
            i = atomic_name();
            break;
        case 4:
            i = atomic_weight();
            break;
        case 5:
            return (0);

        default:
            printf("\t\t\t\tOops!\t\t\t\t");
            printf("Enter a valid choice");
        }
        if (i == -1)
        {

            printf("\t\t\t\t\t!!!!!!!!!! OOPS !!!!!!!!!!\n");
            printf("\t\t\t\t\tYour entry is invalid \n");
            printf("\t\t\t\t\tPlease enter correct details next time \n\n\n\n");
        }
        else if (i == 999)
        {
            continue;
        }
        else
        {
            ch1 = atomic_block(i);
            ch4 = atomic_group(i);
            ch5 = atomic_class(i);
            display(i, ch1, ch2, ch3, ch4, ch5);
        }
        i = 999;
    }while (choice != 6);
    fflush(stdin);

    return (0);
}
//first output i.e., giving choice to user how they  want to search for elements
int get_choice(void)
{
    int input;
    printf("\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^WELCOME^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \t\t\t\t\n");
    printf("\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t\t\tEnter your choice below\n");
    printf("\t\t\t\t1.Search by Atomic No.\n");
    printf("\t\t\t\t2.Search by Atomic Symbol\n");
    printf("\t\t\t\t3.Search by Atomic Name\n");
    fflush(stdin);
    printf("\t\t\t\t4.Search by Atomic Weight\n");
    printf("\t\t\t\t5.To exit the programme\n");
    printf("\t\t\t\t6.to stop;\n");
    scanf("%d", &input);
    return input;
}
//if user want to search by  1(Atomic number)
int atomic_number(void)
{
    int atomicno;
    printf("\t\t\t\tEnter the atomic no. of the element:"); 
    scanf("%d", &atomicno);
    printf("\n\n\n");
    atomicno--;
    if (atomicno >= 0 && atomicno < 118)
    {
        return atomicno;
    }
    else
    {
        //return -1 is to return error;
        return 1;
    }
}
// 
int atomic_name(void)
{
    char name[20];
    int i, flag = 0;
    printf("\t\t\t\tEnter the name of the element\n\t\t\t\t !!!!!Warning!!!!!\n (Please enter the first letter capital and make sure the spelling is correct):\n");
    fflush(stdin);
    scanf("%s", name);
    printf("\n\n\n");
    for (i = 0; i < 118; i++)
    {
        //to compare string entered by user and in name of elements (if they are same(0))
        if (strcmp(name, atoms[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return 1;

    }
}
//if user wants to search by atomic symbol
int atomic_symbol(void)
{
    char symbol[3];
    int i, flag = 0;
    printf("\t\t\t\tEnter the atomic symbol of the element:");
    scanf("%s", symbol);
    printf("\n\n\n");
    for (i = 0; i < 118; i++)
    {
        if (strcmp(symbol, at_symbols[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return 1;
    }
}
//if user wants to search by atomic weight
int atomic_weight(void)
{
    double atomic_mass;
    int i, flag = 0;
    printf("\t\t\t\tEnter the atomic mass of the element:");
    scanf("%lf", &atomic_mass);
    printf("\n\n\n");
    for (i = 0; i < 118; i++)
    {
        if (at_mass[i] == atomic_mass)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return 1;
    }
}
//to find electronic configuration of element
int electronic_configuration()
{
    int i, flag = 0;
    char electronic_config[30];

    for (i = 0; i < 118; i++)
    {
        if (strcmp(electronic_config, elec_config[i]) == 0)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
//to find atomic block of element 
char atomic_block(int i)
{
    char ch = ' ';
    int n = i + 1;
    if (n == 1 || n == 3 || n == 11 || n == 19 || n == 37 || n == 35 || n == 87 || n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        ch = 's';
    }
    else if ((n >= 5 && n <= 10) || (n >= 13 && n <= 18) || (n >= 31 && n <= 36) || (n >= 49 && n <= 54) || (n >= 81 && n <= 86) || (n >= 113 && n <= 118))
    {
        ch = 'p';
    }
    else if (21 <= n <= 30 || 39 <= n <= 48 || 71 <= n <= 80 || 103 <= n <= 112)
    {
        ch = 'd';
    }
    else if (57 <= n <= 70 || 89 <= n <= 102)
    {
        ch = 'f';
    }

    return ch;
}
//to find group of element
int atomic_group(int i)
{
    int group;
    char str[30];
    int n = i + 1;
    if (n == 1 || n == 3 || n == 11 || n == 19 || n == 37 || n == 55 || n == 87)
    {
        group = 1;
    }
    else if (n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        group = 2;
    }
    else if (n == 21 || n == 39 || (n >= 57 && n <= 71) || (n >= 89 && n <= 103))
    {
        group = 3;
    }
    else if (n == 22 || n == 40 || n == 72 || n == 104)
    {
        group = 4;
    }
    else if (n == 23 || n == 41 || n == 73 || n == 105)
    {
        group = 5;
    }
    else if (n == 24 || n == 42 || n == 74 || n == 106)
    {
        group = 6;
    }
    else if (n == 25 || n == 43 || n == 75 || n == 107)
    {
        group = 7;
    }
    else if (n == 26 || n == 44 || n == 76 || n == 108)
    {
        group = 8;
    }
    else if (n == 27 || n == 45 || n == 77 || n == 109)
    {
        group = 9;
    }
    else if (n == 28 || n == 46 || n == 78 || n == 110)
    {
        group = 10;
    }
    else if (n == 29 || n == 47 || n == 79 || n == 111)
    {
        group = 11;
    }
    else if (n == 30 || n == 48 || n == 80 || n == 112)
    {
        group = 12;
    }
    else if (n == 5 || n == 13 || n == 31 || n == 49 || n == 81 || n == 113)
    {
        group = 13;
    }
    else if (n == 6 || n == 14 || n == 32 || n == 50 || n == 82 || n == 114)
    {
        group = 14;
    }
    else if (n == 7 || n == 15 || n == 33 || n == 51 || n == 83 || n == 115)
    {
        group = 15;
    }
    else if (n == 8 || n == 16 || n == 34 || n == 52 || n == 84 || n == 116)
    {
        group = 16;
    }
    else if (n == 9 || n == 17 || n == 35 || n == 53 || n == 85 || n == 117)
    {
        group = 17;
    }
    else if (n == 2 || n == 10 || n == 18 || n == 36 || n == 54 || n == 86 || n == 118)
    {
        group = 18;
    }
    return group;
}
char atomic_class(int i)
{
    char ch = ' ';
    int n = i + 1;
    if (n == 1 || n == 3 || n == 11 || n == 19 || n == 37 || n == 55 || n == 87)
    {
        ch = 'a';
    }
    else if (n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        ch = 'b';
    }
    else if (n >= 57 && n <= 71)
    {
        ch = 'c';
    }
    else if (n >= 89 && n <= 103)
    {
        ch = 'd';
    }
    else if ((n >= 21 && n <= 30) || (n >= 39 && n <= 48) || (n >= 72 && n <= 80) || (n >= 104 && n <= 108))
    {
        ch = 'e';
    }
    else if (n == 13 || n == 31 || n == 49 || n == 50 || n >= 81 && n <= 84)
    {
        ch = 'f';
    }
    else if (n >= 6 && n <= 9 || n >= 15 && n <= 17 || n == 34 || n == 35 || n == 53)
    {
        ch = 'g';
    }
    else if (n == 2 || n == 10 || n == 18 || n == 36 || n == 54 || n == 86 || n == 118)
    {
        ch = 'h';
    }
    else
    {
        ch = 'i';
    }

    return ch;
}
//displaying output for entered element 
void display(int i, char ch1, char ch2, char ch3, char ch4, char ch5)
{
    printf("\t\t\t*******************************Here is your result*****************************************\n");
    printf("\t\t\t___________________________________________________________________________________________\n\n");
    printf("\t\t\tThe atomic number is : %d\n", (i + 1));
    printf("\t\t\tAtomic name is %s\n", atoms[i]);
    printf("\t\t\tAtomic symbol is %.2s\n", at_symbols[i]);
    printf("\t\t\tAtomic Mass is %.2f\n", at_mass[i]);
    printf("\t\t\tThe electronic configuration of the element is :(%s)\n", elec_config[i]);
    printf("\t\t\tThe block is %c\n", ch1);
    printf("\t\t\tThe group of the element is %d\n", ch4);
    fflush(stdin);
    printf("\t\t\tThe state of existence of the element is: %s\n", atomic_state[i]);
    printf("\t\t\tThe class of the element is :");

    if (ch5 == 'a')
    {
        printf("Alkali Metals\n");
    }
    else if (ch5 == 'b')
    {
        printf("Alkaline Earth Metals\n");
    }
    else if (ch5 == 'c')
    {
        printf("Lanthanoids\n");
    }
    else if (ch5 == 'd')
    {
        printf("\t\t\t\t\t\tActinoids\n");
    }
    else if (ch5 == 'e')
    {
        printf("Transition Metals\n");
    }
    else if (ch5 == 'f')
    {
        printf("Post Transition Metals\n");
    }
    else if (ch5 == 'g')
    {
        printf("Reactive Non Metals\n");
    }
    else if (ch5 == 'h')
    {
        printf("Noble Gases\n");
    }
    else if (ch5 == 'i')
    {
        printf("Metalloid\n");
    }
}