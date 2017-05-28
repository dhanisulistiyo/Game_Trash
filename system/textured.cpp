void glTga(void)
{
    glEnable (GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    loadTGA("character/pyon.tga", 0); //ini untuk character kepala kucing
    loadTGA("background/b.tga", 1);
    loadTGA("background/latar.tga", 2);
    loadTGA("background/play.tga", 3);
    loadTGA("background/credits.tga", 4);
    loadTGA("background/exit.tga", 5);
    loadTGA("background/replay.tga", 6);
    loadTGA("background/menu.tga", 7);
    loadTGA("background/kelompok.tga", 8);
    loadTGA("background/latar2.tga", 9);

    loadTGA("number/0.tga", 10);
    loadTGA("number/1.tga", 11);
    loadTGA("number/2.tga", 12);
    loadTGA("number/3.tga", 13);
    loadTGA("number/4.tga", 14);
    loadTGA("number/5.tga", 15);
    loadTGA("number/6.tga", 16);
    loadTGA("number/7.tga", 17);
    loadTGA("number/8.tga", 18);
    loadTGA("number/9.tga", 19);

    loadTGA("live/n10.tga", 20);
    loadTGA("live/n9.tga", 21);
    loadTGA("live/n8.tga", 22);
    loadTGA("live/n7.tga", 23);
    loadTGA("live/n6.tga", 24);
    loadTGA("live/n5.tga", 25);
    loadTGA("live/n4.tga", 26);
    loadTGA("live/n3.tga", 27);
    loadTGA("live/n2.tga", 28);
    loadTGA("live/n1.tga", 29);
    loadTGA("live/n0.tga", 30);


    loadTGA("food/noodle.tga", 31);//load gambar texture ke bidang
    loadTGA("food/egg.tga", 32);
    loadTGA("food/fish.tga", 33);
    loadTGA("food/rice.tga", 34);
    loadTGA("food/burger.tga", 35);
    loadTGA("food/steak.tga", 36);
    loadTGA("food/bbq.tga", 37);
    loadTGA("food/kotor.tga", 38);
    loadTGA("food/kotor2.tga", 39);
    loadTGA("food/kotor3.tga", 40);

}
