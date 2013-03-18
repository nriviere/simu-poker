#ifndef PLAYERSTATISTICS_H_
#define PLAYERSTATISTICS_H_

#define PFLOP 0
#define FLOP 1
#define TURN 2
#define RIVER 3
#define NTOUR 4

#define NORM 0
#define LA 1
#define LP 2
#define SA 3
#define SP 4

#define MINUS -1
#define PLUS 1

#define HAND 0
#define BET 1
#define CALL 2
#define RAISE 3
#define FOLD 4
#define CHECK 5
#define SHDOWN 6
#define SDWIN 7
#define NOSDWIN 8
#define AVGRAISE 9



#include <iostream>
#include <sstream>

using namespace std;

class PlayerStatistics {

  private:

		int playerId;

		int profil;
		int level;

		int nbMain;		//ok
		int nbBet[NTOUR];	//ok
		int nbCall[NTOUR];	//ok
		int nbRaise[NTOUR];	//ok
		int nbFold[NTOUR];	//ok
		int nbCheck[NTOUR];	//ok

		int showDown;		
		int SDWin;	
		int NoSDWin[NTOUR];
		int avgRaise[NTOUR];


	public:
		PlayerStatistics();
		PlayerStatistics(int);
		virtual ~PlayerStatistics();

		int getPlayerId() const;
		int getProfil() const;
		int getLevel() const;
		int getNbMain() const;
		int getNbBet(int) const;
		int getNbCall(int tour) const;
		int getNbRaise(int tour) const;
		int getNbFold(int tour) const;
		int getNbCheck(int tour) const;
		int getShowDown() const;
		int getSDWin() const;
		int getNoSDWin(int tour) const;
		int getavgRaise(int tour) const;

		void setPlayerId(int n);
		void setProfil(int n);
		void setLevel(int n);
		void setNbMain(int n);
		void setNbBet(int tour,int n);
		void setNbCall(int tour,int n);
		void setNbRaise(int tour,int n);
		void setNbFold(int tour,int n);
		void setNbCheck(int tour,int n);
		void setShowDown(int n);
		void setSDWin(int n);
		void setNoSDWin(int tour,int n);
		void setavgRaise(int tour,int n);


		int getVpip();
		int getPfr();
		int getAf(int);
		int getWin();
		int getLeave();

		int setProfil(int vpipNorm, int pfrNorm);
		int setLevel(int low_win, int high_win);

		void incrementStat(int stat, int tour = 0);

		string profilStr();
		string toString() const;

};

#endif /* PLAYERSTAT_H_ */
