#include "PlayerStatistics.h"

PlayerStatistics::PlayerStatistics() {
  playerId = -1;
	nbMain = SDWin = showDown = 0;
	for(int i=0; i<NTOUR; i++){
		nbBet[i] = nbCall[i] = 0;
		nbRaise[i] = nbFold[i] = 0;
		nbCheck[i] = NoSDWin[i] = 0;
		avgRaise[i] = nbAllIn[i] = 0;
	}
	profil = level = 0;
}

PlayerStatistics::PlayerStatistics(int i){
	playerId = i;
	nbMain = SDWin = showDown = 0;
	for(int i=0; i<NTOUR; i++){
		nbBet[i] = nbCall[i] = 0;
		nbRaise[i] = nbFold[i] = 0;
		nbCheck[i] = NoSDWin[i] = 0;
		avgRaise[i] = 0;
	}
	profil = level = 0;
}

PlayerStatistics::~PlayerStatistics() { }

int PlayerStatistics::getVpip() {
	float f = (nbCall[PFLOP]+nbRaise[PFLOP]/nbMain);
	return (int) (f*100);
}

int PlayerStatistics::getPfr(){
	float f = (nbRaise[PFLOP]/nbMain);
	return (int) (f*100);
}

int PlayerStatistics::getAf(int tour){
	int ret = 0;
	if(tour!=PFLOP && tour<NTOUR){
		float f = (nbBet[tour]+nbRaise[tour])/nbCall[tour];
		ret = (int) (f*100);
	}
	return ret;
}

int PlayerStatistics::getWin(){
	int total = 0;
	for(int i=0; i<NTOUR; i++) total += NoSDWin[i];
	float f = (SDWin + total) / (nbCall[PFLOP]+nbCheck[PFLOP]);
	return (int) (f*100);
}

int PlayerStatistics::getLeave(){
	int total = 0;
	for(int i=1; i<NTOUR; i++) total += nbFold[i];
	float f = total / nbCall[PFLOP];
	return (int) (f*100);
}

int PlayerStatistics::setProfil(int vpipNorm, int pfrNorm){

	int ret = NORM;
	int offset = 5;	 

	if(getVpip()>vpipNorm+offset)
		ret = ( getPfr()>pfrNorm ? LA : LP);
	else if(getVpip()<vpipNorm-offset)
		ret = ( getPfr()>pfrNorm ? SA : SP);

	profil = ret;
	return ret;

}

int PlayerStatistics::setLevel(int low_win, int high_win){
	int ret = NORM;

	if(getWin()>high_win) ret = PLUS;
	else if(getWin()<low_win) ret = MINUS;

	level = ret;
	return ret;
}

string PlayerStatistics::profilStr(){
	string ret;
	string level_str, profil_str;

	level_str = " ";
	if(level==PLUS) level_str = "+";
	else if(level == MINUS) level_str = "-";

	switch (getProfil()) {
		case LA:
			profil_str = "Loose Agressive";
			break;
		case SA:
			profil_str = "Tight Agressive";
			break;
		case LP:
			profil_str = "Large Passive";
			break;
		case SP:
			profil_str = "Tight Passive";
			break;
		default:
			profil_str = "Normal";
			break;
	}

	ret = profil_str + " " + level_str;

	return ret;
}

void PlayerStatistics::incrementStat(int stat, int tour){
	switch (stat) {
		case HAND	:	nbMain++;			break;
		case BET	:	nbBet[tour]++;		break;
		case CALL	:	nbCall[tour]++;		break;
		case RAISE	:	nbRaise[tour]++;	break;
		case FOLD	:	nbFold[tour]++;		break;
		case CHECK	:	nbCheck[tour]++;	break;
		case SHDOWN	:	showDown++;			break;
		case SDWIN	:	SDWin++;			break;
		case NOSDWIN:	NoSDWin[tour]++;	break;

		default	:
			cerr<<"incrementStat error!"<<endl;
			break;
	}
}

string PlayerStatistics::toString() const{
    stringstream tmp;
	int total = 0;

	float f = 0;

    if(showDown) f = 100*(SDWin/(float)showDown);

	tmp << "Hand count\t:\t" << nbMain << "\n";
	tmp << "Total Shodown\t:\t" << showDown << "\t";
    tmp << "(Win " << SDWin << "/" << showDown << " ";
	tmp << (int) f << "% )\n";

	tmp << "Stat\tPFlop\tFlop\tTurn\tRiver\tTotal\n";

	tmp << "Bet";
	for(int i=0; i<NTOUR;i++){
		total += nbBet[i];
		tmp << "\t" << nbBet[i];
	}
	tmp << "\t" << total << "\n";

	tmp << "Call";	total = 0;
	for(int i=0; i<NTOUR;i++){
		total += nbCall[i];
		tmp << "\t" << nbCall[i];
	}
	tmp << "\t" << total << "\n";

	tmp << "Check";	total = 0;
	for(int i=0; i<NTOUR;i++){
		total += nbCheck[i];
		tmp << "\t" << nbCheck[i];
	}
	tmp << "\t" << total << "\n";


	tmp << "Raise";	total = 0;
	for(int i=0; i<NTOUR;i++){
		total += nbRaise[i];
		tmp << "\t" << nbRaise[i];
	}
	tmp << "\t" << total << "\n";

	tmp << "All In";	total = 0;
	for(int i=0; i<NTOUR;i++){
		total += nbAllIn[i];
		tmp << "\t" << nbAllIn[i];
	}
	tmp << "\t" << total << "\n";

	tmp << "Fold";	total = 0;
	for(int i=0; i<NTOUR;i++){
		total += nbFold[i];
		tmp << "\t" << nbFold[i];
	}
	tmp << "\t" << total << "\n";

	tmp << "Win";	total = 0;
	for(int i=0; i<NTOUR;i++){
		total += NoSDWin[i];
		tmp << "\t" << NoSDWin[i];
	}
	tmp << "\t" << total << "\n";

	return tmp.str();
}

int PlayerStatistics::getPlayerId() const { return playerId; }
int PlayerStatistics::getNbMain() const { return nbMain; }
int PlayerStatistics::getNbBet(int tour) const { return nbBet[tour]; }
int PlayerStatistics::getNbCall(int tour) const { return nbCall[tour]; }
int PlayerStatistics::getNbRaise(int tour) const { return nbRaise[tour]; }
int PlayerStatistics::getNbFold(int tour) const { return nbFold[tour]; }
int PlayerStatistics::getNbCheck(int tour) const { return nbCheck[tour]; }
int PlayerStatistics::getProfil() const { return profil; }
int PlayerStatistics::getLevel() const { return level; }
int PlayerStatistics::getShowDown() const { return showDown; }
int PlayerStatistics::getSDWin() const { return SDWin; }
int PlayerStatistics::getNoSDWin(int tour) const { return NoSDWin[tour]; }
int PlayerStatistics::getavgRaise(int tour) const { return avgRaise[tour];}

void PlayerStatistics::setPlayerId(int i) { playerId = i; }
void PlayerStatistics::setNbMain(int n) { nbMain = n; }
void PlayerStatistics::setNbBet(int tour,int n) { nbBet[tour] = n; }
void PlayerStatistics::setNbCall(int tour,int n) { nbCall[tour] = n; }
void PlayerStatistics::setNbRaise(int tour,int n) { nbRaise[tour] = n; }
void PlayerStatistics::setNbFold(int tour,int n) { nbFold[tour] = n; }
void PlayerStatistics::setNbCheck(int tour,int n) { nbCheck[tour] = n; }
void PlayerStatistics::setProfil(int n) { profil = n; }
void PlayerStatistics::setLevel(int n) { level = n; }
void PlayerStatistics::setShowDown(int n) { showDown = n; }
void PlayerStatistics::setSDWin(int n) { SDWin = n ;}
void PlayerStatistics::setNoSDWin(int t, int n) { NoSDWin[t]= n; }
void PlayerStatistics::setavgRaise(int t, int n) { avgRaise[t] = n; }

