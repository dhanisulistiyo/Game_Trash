
void NulisHighScore () {
  if (score > highscore) {
    highscore = score;
  ofstream myfile;
  myfile.open ("highscore.txt");
  myfile << highscore;
  myfile.close();
  }
}

void GetHighScore () {
  FILE *myfile;
  if ( (myfile = fopen("highscore.txt", "r+")) == NULL) {
    score = 0;
  }
  else{
    if(fscanf(myfile, "%d", &highscore) != EOF){
    }
  }
  fclose(myfile);
}

