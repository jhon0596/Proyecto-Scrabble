//
// Created by gacova on 16/03/19.
//

#include "VerificadorPal.h"

std::string VerificadorPal::buscardicc(char pal) {
    std::string DFDic;
    switch (pal){
        case 'A':
            DFDic="../palabras/a.txt";
            break;
        case 'B':
            DFDic="../palabras/b.txt";
            break;
        case 'C':
            DFDic="../palabras/c.txt";
            break;
        case 'D':
            DFDic="../palabras/d.txt";
            break;
        case 'E':
            DFDic="../palabras/e.txt";
            break;
        case 'F':
            DFDic="../palabras/f.txt";
            break;
        case 'G':
            DFDic="../palabras/g.txt";
            break;
        case 'H':
            DFDic="../palabras/h.txt";
            break;
        case 'I':
            DFDic="../palabras/i.txt";
            break;
        case 'J':
            DFDic="../palabras/j.txt";
            break;
        case 'L':
            DFDic="../palabras/l.txt";
            break;
        case 'M':
            DFDic="../palabras/m.txt";
            break;
        case 'N':
            DFDic="../palabras/n.txt";
            break;
            /*case "Ñ":// arreglar despues
                DFDic="../palabras/nn.txt";
                break;*/
        case 'O':
            DFDic="../palabras/o.txt";
            break;
        case 'P':
            DFDic="../palabras/p.txt";
            break;
        case 'Q':
            DFDic="../palabras/q.txt";
            break;
        case 'R':
            DFDic="../palabras/r.txt";
            break;
        case 'S':
            DFDic="../palabras/s.txt";
            break;
        case 'T':
            DFDic="../palabras/t.txt";
            break;
        case 'U':
            DFDic="../palabras/u.txt";
            break;
        case 'V':
            DFDic="../palabras/v.txt";
            break;
        case 'X':
            DFDic="../palabras/x.txt";
            break;
        case 'Y':
            DFDic="../palabras/y.txt";
            break;
        case 'Z':
            DFDic="../palabras/z.txt";
            break;

        default:
            DFDic="../palabras/nn.txt";
            break;
    }
    return DFDic;
}

bool VerificadorPal::buscarPal(std::string pal) {
    std::string line;

    std::ifstream myfile(buscardicc(pal.at(0)));
    bool enDICC;

    std::string palabra;
    if (myfile.is_open())
    {

        while ( getline (myfile,line) )
        {
            line.pop_back();//elimmina \r que tiene el string
            palabra =line;



            if(pal==palabra){
                enDICC = true;
                break;
            } else{enDICC = false;}
        }
        myfile.close();
        palabra="";
    }

    else std::cout << "Unable to open file";

    return enDICC;
}

