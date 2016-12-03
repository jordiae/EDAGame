#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Sovereignv2


// TODO: defines
#define KNIGHT_HEALTH_CRITERIUM 40
#define WITCH_DENSITY_CRITERIUM 1 
#define WITCH_ROUND_ATTACK_STRATEGY_CRITERIUM 20

// unitorwall
#define wall 0
#define farmer_team 1
#define farmer_enemy 2
 #define knight_team 3
 #define knight_enemy 4
 #define witch_team 5
 #define witch_enemy 6
 #define empty 7

// colors
 #define Self 0
 #define Enemy 1
 #define None 2

// TODO: check if haunted implies active witch or only witch

// TODO: strategies

/*
struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

    struct EvalCell {
    string unitOrWall = "empty";
    bool knighted = false;
    bool extra_haunted = false;
    string color = "None";
  } ;

  vector<int> f;
  vector<int> k;
  vector<int> w;
  Dir farmer_movements[8] = {Left,Top,Right,Bottom,BR,RT,TL,LB};

  typedef vector< vector<EvalCell> > Matrix;
  Matrix M(rows(),vector<EvalCell>(cols()));

  
  // TODO extra_haunted should take into account whether the witch is active, and it should check many positions instead of only one
  inline bool extra_haunted(Pos pos) {
    Cell c = cell(pos);
    if (c.haunted) {
      return true;
    }
    for (int i = 0; i < 8; i++) {
      Pos pos_aux = pos+farmer_movements[i];
      c = cell(pos_aux);
      if (c.haunted)
        return true;
    }
    return false;
  }
  
  // TODO: check if active
  inline int self_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player == 0 and u.type != Witch) {
          if (u.type == Farmer)
            damage += 1;
          else if (u.type == Knight)
            damage += 2;
        }
      }
    }
    Cell c = cell(pos+Left+Left);
    Unit u;
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Top+Top);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Right+Right);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Bottom+Bottom);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player == 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    return damage;
  }

    inline int other_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      if (c.id != -1) {
        Unit u = unit(c.id);
        if (u.player != 0 and u.type != Witch) {
          if (u.type == Farmer)
            damage += 1;
          else if (u.type == Knight)
            damage += 2;
        }
      }
    }
    Cell c = cell(pos+Left+Left);
    Unit u;
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Top+Top);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Right+Right);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    c = cell(pos+Bottom+Bottom);
    if (c.id != -1) {
      u = unit (c.id);
      if (u.player != 0 and u.type != Witch) {
        if (u.type == Farmer)
          damage += 1;
        else if (u.type == Knight)
          damage += 2;
      }
    }
    return damage;
  }
/*
  inline bool self_haunted(Pos pos) {
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+farmer_movements[i]);
      Unit u = unit(c.id);
      if (u.id != -1 and u.player == 0 and u.type != Witch)
        return true;
    }
    Cell c = cell(pos+Left+Left);
    Unit u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Top+Top);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Right+Right);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    c = cell(pos+Bottom+Bottom);
    u = unit (c.id);
    if (u.id != -1 and u.player == 0 and u.type != Witch)
      return true;
    return false;
  }*/
  
  inline bool knighted(Pos pos) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+farmer_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight)
            return true;
        }
    }

   return false;
  }

  inline bool knighted2(Pos pos,int& health) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+farmer_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight) {
            health = u.health;
            return true;
          }
        }
    }

   return false;
  }


  // TODO organize



  bool check_farmer_opt(Pos pos, UnitType unitType, int health, bool escape) {
    Cell c = cell(pos);
    EvalCell evalCell = M[pos.i][pos.j];
    if (unitType == Farmer) {
      if (evalCell.unitOrWall != empty)
        return false;
      if (c.haunted or evalCell.knighted)
        return false; // TODO TAKE INTO ACCOUNT COLOR
      if (evalCell.extra_haunted and not escape)
        return false;
      return true;
    }
    else if (unitType == Knight){
      if (evalCell.unitOrWall == wall or evalCell.unitOrWall == farmer_team or evalCell.unitOrWall == knight_team or evalCell == witch_team or evalCell == witch_enemy)
        return false;
      if (c.haunted)
        return false;
      if (evalCell.extra_haunted and not escape)
        return false;
      if (evalCell.knighted and not escape and health < KNIGHT_HEALTH_CRITERIUM) // TODO: other's knight health?
        return false;
      return true;
    }
    else if (unitType == Witch) {
      if (unitOrWall == wall or unitOrWall == witch_enemy or unitOrWall == witch_team)
        return false;
      if (self_haunted(pos) > WITCH_DENSITY CRITERIUM and round() > WITCH_ROUND_ATTACK_STRATEGY_CRITERIUM) { // (abans self_haunted > 0) ROUND: clauissim!!! > 20 EP EP
        return false;
      }
      return true;
    }
    else
      return false;
  }

 // TODO: apart from escape, also priority
  bool check_targetable_opt(Pos pos, UnitType unitType, int health, bool escape) {
    EvalCell evalCell = M[pos.i][pos.j];
    if (unitType == Farmer) {
      if (escape)
        return true;
      else if (unitType != Self)
        return true;
      else
        return false;
    }
    else if (unitType == Knight) {
      if (escape)
        return true;
      if (evalCell.unitOrWall == farmer_enemy)
        return true;
      if (evalCell.unitOrWall == knight_enemy) {
        Cell c = cell(pos);
        Unit u = unit(c.id)
        if (health > u.health) {
              return true;
            else
              return false;
          }
      }
      else
        return false;
    }
    else if (unitType == Witch) {
      if (other_haunted(pos) > WITCH_DENSITY) // > = 0 ?
        return true;
    }
    else
      return false;
  }

  inline bool bfs(int id, bool escape) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);

    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    set<Pos> s_visited; // TODO: this set is not necessary, it could be done with the map
    UnitType unitType = u.type;
    int n = 0;
    vector<Dir> mov(8);
    if (u.type == Farmer or u.type == Witch) {
      n = 4;
      vector<Dir> mov_aux(n);
      for (int i = 0; i < n; i++)
        mov_aux[i] = farmer_movements[i];
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = mov_aux[i];
    }
    else if (u.type == Knight) {
      n = 8;
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = farmer_movements[i];

    }
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < n; i++) {
        if (check_farmer_opt(pos+mov[i],unitType,u.health,escape)) {
          if (check_targetable_opt(pos+mov[i],unitType,u.health,escape)) {
            //FOUND
            m.insert(make_pair(pos+mov[i],pos));
            Pos pos_dir = pos+mov[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            if (u.pos+Left == pos_aux) {
              command(id,Left);
            }
            else if (u.pos+Top == pos_aux) {
              command(id,Top);
            }
            else if (u.pos+Right == pos_aux) {
              command(id,Right);
            }
            else if (u.pos+Bottom == pos_aux) {
              command(id,Bottom);
            }
            else if (unitType == Knight) {
              if (u.pos+BR == pos_aux) {
                command(id,BR);
              }
              else if (u.pos+RT == pos_aux) {
                command(id,RT);
              }
              else if (u.pos+TL == pos_aux) {
                command(id,TL);
              }
              else if (u.pos+LB == pos_aux) {
                command(id,LB);
              }
            }
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+mov[i]) == s_visited.end()) {
              s_visited.insert(pos+mov[i]); // no necessari pels farmers, sí pels knights
              q.push(pos+mov[i]);
              m.insert(make_pair(pos+mov[i],pos));
            }
          }
        }
      }
    }
    // TODO: if safe, command none. Else, escape. Or health...
    /*bool b;
    if (extra_haunted(u.pos) or knighted(u.pos)) {
      cerr << "YEP" << endl;
      b = bfs_escape(id);
    }*/
    if (not b)
      command(id,None);
    return false;
  }

  
  void setCheck(Pos pos, EvalCell &evalCell) {
    Cell c = cell(pos);
    if (c.type == Wall)
      evalCell.unitOrWall = wall;
    else if (c.type == Empty) {
      if (c.id != -1) {
        Unit u = unit(pos);
        switch (u.type) {
          case Farmer:
            if (u.player == 0)
              evalCell.unitOrWall = farmer_team;
            else
              evalCell.unitOrWall = farmer_enemy;
            break;
          case Knight:
            if (u.player == 0)
              evalCell.unitOrWall = knight_team;
            else
              evalCell.unitOrWall = knight_enemy;
            break;
          case Witch:
            if (u.player == 0)
              evalCell.unitOrWall = witch_team;
            else
              evalCell.unitOrWall = witch_enemy;
            break;
        }
      }
      else
        evalCell.unitOrWall = empty;
    }

    evalCell.knighted = knighted(pos);
    
    if (c.haunted)
      evalCell.extra_haunted = true;
    else
      evalCell.extra_haunted = extra_haunted(pos);



    if (c.owner == 0)
      evalCell.color = Self;
    else if (c.owner == -1)
      evalCell.color = None;
    else
      evalCell.color = Enemy;

  }


  // TODO: could be more efficient
  void readBoard() {
    for (int i = 0; i < M.size(); i++) {
      for (int j = 0; j < M[0].size(); j++) {
        Pos pos(i,j);
        setCheck(pos,M[i][j]);
      }
    }
  }

  void move_farmer(int id) {
    // TODO: decide wheter command(None)
    // TODO: health criterium?
    Unit u = unit(id);
    EvalCell evalCell = M[u.pos.i][u.pos.j];
    bool escape = false;
    if (evalCell.extra_haunted or evalCell.knighted)
      escape = true;
    bfs(id,escape);
  }

  void move_knight(int id) {
    // TODO: decide wheter command(None)
    Unit u = unit(id);
    EvalCell evalCell = M[u.pos.i][u.pos.j];
    bool escape = false;
    if (evalCell.extra_haunted or (evalCell.knighted and u.health < KNIGHT_HEALTH_CRITERIUM))
      escape = true;
    bfs(id,escape);
  }

  void move_witch(int id) {
    bfs(id,false);
    // TODO: maybe I should force the witch to "escape" if it's deactivated.
  }

  void moveAllFarmers() {
    // TODO: cooperation?
    f = farmers(0);
    for (int i = 0; i < f.size(); i++)
        move_farmer(f[i]);
  }

  void moveAllKnights() {
    // TODO: cooperation?
    k = knights(0);
    for (int i = 0; i < k.size(); i++)
        move_knight(k[i]);
  }

  void moveAllWitches() {
    // TODO: cooperation?
    // TODO: defensive?
    for (int i = 0; i < k.size(); i++)
        move_witch(k[i]);
    w = witches(0);
  }

  void moveAllUnits() {
    moveAllWitches();
    moveAllKnights();
    moveAllFarmers();
  }*/




  /**
   * Types and attributes for your player can be defined here.
   */

   // unitorwall

   /*
#define wall 0
#define farmer_team 1
#define farmer_enemy 2
 #define knight_team 3
 #define knight_enemy 4
 #define witch_team 5
 #define witch_enemy 6
 #define empty 7

// colors
 #define Self 0
 #define Enemy 1
 #define None 2*/






  /**
   * Play method, invoked once per each round.
   */

  virtual void play () {
    /*readBoard();
    moveAllUnits();*/
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
