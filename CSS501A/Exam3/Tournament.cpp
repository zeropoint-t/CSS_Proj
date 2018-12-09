#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Competitor{
    private:
        string name;
        int wins = 0;
        int losses = 0;
        int skill_level = 0;
    public:
        Competitor(){}
        Competitor(string name){
            this->name = name;
        }

        void setSkillLevel(int lvl){
            this->skill_level = lvl;
        }

        int getSkillLevel() const{
            return this->skill_level;
        }

        string getName(){
            return this->name;
        }

        void incrementWin(){wins++;}

        void incrementLosses(){losses++;}

        void setWins(int wins){
            if(wins > 0 && wins < 100){
                this->wins = wins;
            }else{
                throw out_of_range("Wins are negative or too many wins");
            }
        }

        void setLosses(int losses){
            if(losses > 0 && losses < 100){
                this->losses = losses;
            }else{
                throw out_of_range("losses are negative or too many losses");
            }
        }

        double getWins() const{
            return wins;
        }

        double getLosses() const{
            return losses;
        }

        double getWLRatio() const{
            return losses == 0 ? 0 : wins / losses;
        }

        Competitor& operator*(Competitor& competitor){
            // cout << this->name << " at " << this->getSkillLevel() << "  vs  " << competitor.name << " at " << competitor.getSkillLevel() << endl;
            if(this->getSkillLevel() > competitor.getSkillLevel()){
                this->wins++;
                competitor.losses++;
                // cout << "Winner is " << this->name << endl;
                return *this;
            }
            else{
                competitor.wins++;
                this->losses++;
                // cout << "Winner is " << competitor.name << endl;
                return competitor;
            }
        }

        bool operator<(const Competitor& competitor) const{
            if(this->getSkillLevel() < competitor.getSkillLevel())
                return true;
            else
                return false;
        }
};

template<class T>
class Group{
    private:
        queue<T> competitors;
    public:
        Group(){}
        void Add(T t){
            competitors.push(t);
        }
        bool Empty(){
            return competitors.empty();
        }
        int GetSize(){
            return competitors.size();
        }
        T GetNextCompetitor(){
            if(competitors.empty() == false){
                T nextCompetitor = competitors.front();
                competitors.pop();
                return nextCompetitor;
            }else{
                throw runtime_error("There is no more competitors");
            }
        }
};

enum MatchTypeEnum { sorted, rnd };

template<class T>
class Tournament{
    private:

    protected:
        T winner;
        MatchTypeEnum matchType = rnd;
        int roundPlayed = 0;
    public:
        Tournament(MatchTypeEnum matchType){
            this->matchType = matchType;
        }
        virtual ~Tournament(){}
        virtual T& GetWinner() = 0;
        virtual void Enter(T t) = 0;
        int getRoundsPlayed(){
            return this->roundPlayed;
        }
};

template<class T>
class Match;

template<class T>
class SingleElimination_Tournament;

template<class T>
ostream& operator<<(ostream& outstream, SingleElimination_Tournament<T> t){
    T winner = t.GetWinner();
    cout << "-----Champion Stats-----" << endl;
    cout << "The Champion is " << winner.getName() << endl;
    cout << "Wins: " << winner.getWins() << endl;
    cout << "Losses: " << winner.getLosses() << endl;
    cout << "Rounds played: " << t.getRoundsPlayed() << endl;

    cout << endl;

    t.displayRoster();

    return outstream;
}

template<class T>
bool sortByRank(T& comp1, T& comp2){
    return comp1 < comp2;
}

template<class T>
class SingleElimination_Tournament : public Tournament<T>{

    template<class d>
    friend ostream& operator<<(ostream& outstream, const SingleElimination_Tournament<d> t);

    private:
        int numOfGroups = 0;
        vector<Group<T>> groups;//keeps track of groups
        queue<Match<T>*> matches;//keeps track of matches
        vector<T> competitors;

        void clear(Match<T>* match){
            if(match->Match1 != nullptr)
                clear(match->Match1);

            if(match->Match2 != nullptr)
                clear(match->Match2);

            delete match;
        }

        void display(Match<T>* match, int&& i) const{

            if(match->Match1 != nullptr)
                display(match->Match1, move(i));

            if(match->Match2 != nullptr)
                display(match->Match2, move(i));

            if(match->Match1 != nullptr){
                cout << "---Game " << i++ << "---" << endl;
                cout << match->Match1->Winner.getName() << " vs " << match->Match2->Winner.getName() << endl;
                cout << "Winner is " << match->Winner.getName() << endl << endl;
            }
        }
    public:
        SingleElimination_Tournament(const SingleElimination_Tournament& tournament):Tournament<T>(tournament.matchType){

            this->numOfGroups = tournament.numOfGroups;
            this->groups = tournament.groups;
            this->competitors = tournament.competitors;

            //perform breadth first search to deep copy matches
            if(tournament.matches.size() > 0){
                queue<Match<T>*> orig_q;//keep track of original matches
                queue<Match<T>*> new_q;//keep track of new matches

                Match<T>* origMatch = tournament.matches.front();
                
                Match<T>* newMatch = new Match<T>;

                //create new Match1 & Match2 pointers
                newMatch->Winner = origMatch->Winner;
                if(origMatch->Match1 != nullptr)
                    newMatch->Match1 = new Match<T>;
                if(origMatch->Match2 != nullptr)
                    newMatch->Match2 = new Match<T>;

                //put the champaion match into matches
                this->matches.push(newMatch);

                //push original champion match's match 1 and match2 into a queue for BFS
                orig_q.push(origMatch->Match1);
                orig_q.push(origMatch->Match2);

                //push new champion match's match 1 and match2 into a queue for BFS
                new_q.push(newMatch->Match1);
                new_q.push(newMatch->Match2);

                while(!orig_q.empty()){
                    origMatch = orig_q.front();
                    orig_q.pop();

                    newMatch = new_q.front();
                    new_q.pop();

                    if(origMatch != nullptr){
                        //create new Match1 & Match2 pointers
                        newMatch->Winner = origMatch->Winner;
                        if(origMatch->Match1 != nullptr)
                            newMatch->Match1 = new Match<T>;
                        if(origMatch->Match2 != nullptr)
                            newMatch->Match2 = new Match<T>;

                        //push original champion match's match 1 and match2 into a queue for BFS
                        orig_q.push(origMatch->Match1);
                        orig_q.push(origMatch->Match2);

                        //push new champion match's match 1 and match2 into a queue for BFS
                        new_q.push(newMatch->Match1);
                        new_q.push(newMatch->Match2);
                    }
                }
            }
        }

        SingleElimination_Tournament(MatchTypeEnum matchType, int numOfGroups):Tournament<T>(matchType){
            if(numOfGroups < 1 || numOfGroups > 4)
                throw runtime_error("Number of groups can not be less 0 or greater than 4!!");

            this->matchType = matchType;
            this->numOfGroups = numOfGroups;
            for(int i = 0; i < numOfGroups; i++){
                Group<T> g;
                this->groups.push_back(g);
            }
        }

        ~SingleElimination_Tournament(){
            if(!matches.empty() && matches.size() == 1){
                Match<T>* championship = matches.front();
                matches.pop();
                clear(championship);
            }
        }

        void displayRoster() const{
            this->display(this->matches.front(), 1);
        }

        void Enter(T t) override{
            this->competitors.push_back(t);
        }

        T& GetWinner() override{
            //*********************************
            //sort competitors
            //*********************************
            if(this->matchType == rnd){
                for(int i = 0; i < this->competitors.size(); i++){
                    int rndIndex = rand() % (this->competitors.size()-1); 
                    auto element = this->competitors.at(rndIndex);
                    this->competitors.erase(this->competitors.begin() + rndIndex);
                    this->competitors.push_back(element);
                }
            }else if(this->matchType == sorted){
                sort(this->competitors.begin(), this->competitors.end(), sortByRank<T>);
            }

            cout << this->competitors.size() << endl;

            //*********************************
            //assign competitors into groups
            //*********************************
            for(auto cmp = competitors.begin(); cmp != competitors.end();){
                for(auto g = groups.begin(); g != groups.end(); g++){
                    g->Add(*cmp);
                    cmp++;
                    if(cmp == this->competitors.end())
                        break;
                }
            }

            //*************************************
            //create matches all the way to the top
            //*************************************
            for(auto g = groups.begin(); g != groups.end(); g++){
                //this is the very first round of group matches at leaf level
                queue<Match<T>*> groupMatches;
                while(!g->Empty())
                {
                    if(g->GetSize() >= 2){//more than 2 competitors are left
                        Match<T>* curMatch = new Match<T>;
                        curMatch->Match1 = new Match<T>;
                        curMatch->Match2 = new Match<T>;
                        curMatch->Match1->Winner = g->GetNextCompetitor();
                        curMatch->Match2->Winner = g->GetNextCompetitor();
                        curMatch->Winner = curMatch->Match1->Winner * curMatch->Match2->Winner;
                        this->roundPlayed++;
                        groupMatches.push(curMatch);
                    }else{//only 1 competitor left
                        Match<T>* curMatch = new Match<T>;
                        curMatch->Match1 = new Match<T>;
                        curMatch->Match2 = new Match<T>;
                        curMatch->Match1->Winner = g->GetNextCompetitor();
                        curMatch->Match2->Winner = curMatch->Match1->Winner;
                        curMatch->Winner = curMatch->Match1->Winner;
                        this->roundPlayed++;
                        groupMatches.push(curMatch);
                    }
                }

                //let the first level winners compete all the way to a group champion
                while(groupMatches.size() > 1){
                    Match<T>* match1 = groupMatches.front();
                    groupMatches.pop();
                    Match<T>* match2 = groupMatches.front();
                    groupMatches.pop();

                    Match<T>* curMatch = new Match<T>;
                    curMatch->Match1 = match1;
                    curMatch->Match2 = match2;
                    //winner here
                    curMatch->Winner = curMatch->Match1->Winner * curMatch->Match2->Winner;
                    this->roundPlayed++;

                    groupMatches.push(curMatch);
                }

                matches.push(groupMatches.front());
                groupMatches.pop();
            }

            //Find tournament champions amongst all group champions
            while(matches.size() > 1){
                Match<T>* match1 = matches.front();
                matches.pop();
                Match<T>* match2 = matches.front();
                matches.pop();

                Match<T>* curMatch = new Match<T>;
                curMatch->Match1 = match1;
                curMatch->Match2 = match2;
                //winner here
                curMatch->Winner = curMatch->Match1->Winner * curMatch->Match2->Winner;
                this->roundPlayed++;

                matches.push(curMatch);
            }

            Match<T>* championship = matches.front();
            this->winner = championship->Winner;
            return this->winner;
        }
};

template<class T>
class Match{
    private:

    public:
        Match(){}
        ~Match(){
            cout << "Match with winner " << Winner.getName() << " is destroyed" << endl;
        }
        Match<T>* Match1 = nullptr;
        Match<T>* Match2 = nullptr;
        T Winner;
};

int main(){
    SingleElimination_Tournament<Competitor>* t = 
        new SingleElimination_Tournament<Competitor>(sorted,2);

    for(int i = 0; i < 8; i++){
        string name = "Competitor " + to_string(i);
        Competitor c(name);
        c.setSkillLevel(i);
        t->Enter(c);
    }

    cout << *t << endl;

    // SingleElimination_Tournament<Competitor> copyTournament = *t;

    // cout << copyTournament << endl;

    delete t;
}