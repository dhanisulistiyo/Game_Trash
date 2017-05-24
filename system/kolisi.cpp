bool isKena(int i){
//    cout    <<"B  "<< x << "   " <<  makanan[i].getPosX() << "   "
//            << mainChar.y << "   " << makanan[i].getPosY() << endl;
    double  miaw1 = pow(mainChar.x + x - makanan[i].getPosX(), 2),
            miaw2 = pow(50 - makanan[i].getPosY(), 2),
            miaw = 100.0;

    miaw = sqrt(miaw1+miaw2);
    if(miaw <= 80){
        return true;
    }else{
        return false;
    }
}

bool isLewat(int i){
    if(makanan[i].getPosY() > -20 && makanan[i].getPosY() < 0){
        return true;
    }else{
        return false;
    }
}
