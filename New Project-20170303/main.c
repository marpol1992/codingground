#include <stdio.h>
void ReadEprom(unsigned char adress_slave, unsigned char adress_input, unsigned char *adress_executive_relay, unsigned char osiem, unsigned int szesnascie);
int main()
{
    unsigned char buff[5] = {0,0,0,0,0};
     ReadEprom(10,8,buff,0X0A,0X8739);
     int i;
     for(i = 0;i<2; i++)
     printf("%d element bufora rowna sie: %04X \n",i,buff[i]);
    return 0;
}

void ReadEprom(unsigned char adress_slave, unsigned char adress_input, unsigned char *adress_executive_relay, unsigned char osiem, unsigned int szesnascie)
{
    unsigned int id_slave_input = (adress_slave<<4) + adress_input;
    printf("*********************************************************\n");
    printf("Id slave input: %04X\n",id_slave_input);
    unsigned int Flash_id_slave_input;
	unsigned int savedTBLPAG;
	unsigned int pOffset;
	unsigned int i,j;
	unsigned int uiData;
	unsigned int uiIdx;
    unsigned long flash_data;


	
			uiIdx = (192*j)+i;

			uiData = osiem;
            flash_data = (uiData<<16);                            //zamiana na liczbe 3 Bajtową
             printf("po przesuniecu << o 16: %06X \n",flash_data);
			uiData =szesnascie;
            flash_data = flash_data + uiData;                   //dodanie 2 mlodszych Bajtów
             printf("po dodaniu: %06X \n",flash_data);
            Flash_id_slave_input = flash_data>>12;              //zamiana liczby na 1,5 Bajtową
            printf("po przesunieciu o 12 >> %06X \n",Flash_id_slave_input);
            if(Flash_id_slave_input == id_slave_input){         //sprawdzenie czy odczytana "instrukcja" (3Bajty) zawierają adres slave i input
                 printf("wszedłem\n");
                flash_data = flash_data & 0xFFF;
                *(adress_executive_relay++) = (flash_data >> 8) ;    //pozyskanie 4bitow adresu przekaznika
                *(adress_executive_relay++) = (unsigned char) flash_data;   // uzyskanie adresu sterownika wykonawczego
            }else{};


}