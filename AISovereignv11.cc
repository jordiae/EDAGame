#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Sovereignv11

#define NOT_ESCAPE_MAX 0
#define NOT_ESCAPE_MIN 1
#define ESCAPE 2
#define ESCAPE_FAILED_DO_SOMETHING 3


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  inline bool extra_haunted(Pos pos) {
    Cell c = cell(pos);
    if (c.haunted) {
      return true;
    }
    for (int i = 0; i < 8; i++) {
      Pos pos_aux = pos+movements[i];
      c = cell(pos_aux);
      if (c.haunted)
        return true;
    }
    return false;
  }

  inline int self_haunted(Pos pos) {
    int damage = 0;
    for (int i = 0; i < 8; i++) {
      Cell c = cell(pos+movements[i]);
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
      Cell c = cell(pos+movements[i]);
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
  
  inline bool knighted(Pos pos) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+movements[i]);
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
        Cell c = cell(pos+movements[i]);
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




  inline bool check_possible_farmer_not_escape_max(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (extra_haunted(pos))
      return false;
    if (c.id != -1)
      return false;
    if (knighted(pos))
      return false;
    return true;
  }

  inline bool check_possible_farmer_not_escape_min(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (extra_haunted(pos))
      return false;
    if (c.id != -1)
      return false;
    if (knighted(pos))
      return false;
    return true;
  }

  inline bool check_possible_farmer_escape(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (extra_haunted(pos))
      return false;
    if (c.id != -1)
      return false;
    if (knighted(pos))
      return false;
    return true;
  }

  inline bool check_possible_farmer_escape_failed_do_something(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (c.id != -1)
      return false;
    return true;
  }

  
  inline bool check_possible_knight_not_escape_max(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (extra_haunted(pos))
      return false;
    if (c.id != -1)
      return false;
    int health_en;
    if (knighted2(pos,health_en) and health_en > health)
      return false;
    return true;
  }

  inline bool check_possible_knight_not_escape_min(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (extra_haunted(pos))
      return false;
    if (c.id != -1)
      return false;
    int health_en;
    if (knighted2(pos,health_en) and health_en > health)
      return false;
    return true;
  }

  inline bool check_possible_knight_escape(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (extra_haunted(pos))
      return false;
    if (c.id != -1)
      return false;
    int health_en;
    if (knighted2(pos,health_en) and health_en > health)
      return false;
    return true;
  }

  inline bool check_possible_knight_escape_failed_do_something(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.haunted)
      return false;
    if (c.id != -1)
      return false;
    return true;
  }


  inline bool check_possible_witch_not_escape_max(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.id != -1) {
      Unit u = unit(c.id);
      if (u.player == 0)
        return false;
      if (u.type == Witch)
        return false;
      return true;
    }
    if (self_haunted(pos) > 1 and round() > 20) { // (abans self_haunted > 0) ROUND: clauissim!!! > 20 EP EP
     return false;
    }
      /*if (self_haunted(pos) > 5 and round() <= 20) {
        return false;
      }*/
    return true;
  }

  inline bool check_possible_witch_not_escape_min(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.type == Wall)
      return false;
    if (c.id != -1) {
      Unit u = unit(c.id);
      if (u.player == 0)
        return false;
      if (u.type == Witch)
        return false;
      return true;
    }
    if (self_haunted(pos) > 1 and round() > 20) { // (abans self_haunted > 0) ROUND: clauissim!!! > 20 EP EP
     return false;
    }
      /*if (self_haunted(pos) > 5 and round() <= 20) {
        return false;
      }*/
    return true;
  }




  inline bool check_targetable_farmer_not_escape_max(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.owner > 0)
      return true;
    else
      return false;
  }

  inline bool check_targetable_farmer_not_escape_min(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
  }

  inline bool check_targetable_farmer_escape(Pos pos, int health) {
    return true;
  }

  inline bool check_targetable_farmer_escape_failed_do_something(Pos pos, int health) {
    return true;
  }
  
  inline bool check_targetable_knight_not_escape_max(Pos pos, int health) {
    Cell c = cell(pos);
    if (c.id != -1) {
      Unit u = unit(c.id);
      if (u.player == 0)
        return false;
      else {
        if (u.type == Farmer)
          return true;
        else if (u.type == Knight and health > u.health) {
          return true;
        }
        else
          return false;
      }
    }
    else
      return false;
  }

  inline bool check_targetable_knight_not_escape_min(Pos pos, int health) {
    return true;
  }

  inline bool check_targetable_knight_escape(Pos pos, int health) {
    return true;
  }

  inline bool check_targetable_knight_escape_failed_do_something(Pos pos, int health) {
    return true;
  }

  inline bool check_targetable_witch_not_escape_max(Pos pos, int health) {
    if(other_haunted(pos) > 3)
        return true;
  }

  inline bool check_targetable_witch_not_escape_min(Pos pos, int health) {
    if(other_haunted(pos) > 0)
        return true;
  }



  inline bool check_possible(Pos pos,UnitType unitType, int health, int escape, bool first_pos) {
    if ((unitType == Farmer or (unitType == Knight and not check_targetable(pos,unitType,health,escape))) and already_moved.find(pos) != already_moved.end() and first_pos) {
      return false;
    }
    switch (escape) {
      case NOT_ESCAPE_MAX:
        if (unitType == Farmer)
          return check_possible_farmer_not_escape_max(pos,health);
        else if (unitType == Knight)
          return check_possible_knight_not_escape_max(pos,health);
        else
          return check_possible_witch_not_escape_max(pos,health);
      case NOT_ESCAPE_MIN:
        if (unitType == Farmer)
          return check_possible_farmer_not_escape_min(pos,health);
        else if (unitType == Knight)
          return check_possible_knight_not_escape_min(pos,health);
        else
          return check_possible_witch_not_escape_min(pos,health);
      case ESCAPE:
        if (unitType == Farmer)
          return check_possible_farmer_escape(pos,health);
        else
          return check_possible_knight_escape(pos,health);
      case ESCAPE_FAILED_DO_SOMETHING:
        if (unitType == Farmer)
          return check_possible_farmer_escape_failed_do_something(pos,health);
        else
          return check_possible_knight_escape_failed_do_something(pos,health);
    }

  }
  
  inline bool check_targetable(Pos pos,UnitType unitType, int health, bool escape) {
    /*if (not escape and already_targeted.find(pos)!= already_targeted.end())
      return false;*/

    switch (escape) {
      case NOT_ESCAPE_MAX:
        if (unitType == Farmer)
          return check_targetable_farmer_not_escape_max(pos,health);
        else if (unitType == Knight)
          return check_targetable_knight_not_escape_max(pos,health);
        else
          return check_targetable_witch_not_escape_max(pos,health);
      case NOT_ESCAPE_MIN:
        if (unitType == Farmer)
          return check_targetable_farmer_not_escape_min(pos,health);
        else if (unitType == Knight)
          return check_targetable_knight_not_escape_min(pos,health);
        else
          return check_targetable_witch_not_escape_min(pos,health);
      case ESCAPE:
        if (unitType == Farmer)
          return check_targetable_farmer_escape(pos,health);
        else
          return check_targetable_knight_escape(pos,health);
      case ESCAPE_FAILED_DO_SOMETHING:
        if (unitType == Farmer)
          return check_targetable_farmer_escape_failed_do_something(pos,health);
        else
          return check_targetable_knight_escape_failed_do_something(pos,health);
    }


  }

  inline bool bfs(int id, int escape) {
    bool first_pos = true;
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    UnitType unitType = u.type;
    int n = 0;
    vector<Dir> mov(8);
    if (u.type == Farmer or u.type == Witch) {
      n = 4;
      vector<Dir> mov_aux(n);
      for (int i = 0; i < n; i++)
        mov_aux[i] = movements[i];
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = mov_aux[i];
    }
    else if (u.type == Knight) {
      n = 8;
      vector<int> randp = random_permutation(n);
      for (int i = 0; i < n; i++)
        mov[randp[i]] = movements[i];

    }
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < n; i++) {
        if (check_possible(pos+mov[i],unitType,u.health,escape,first_pos)) {
          if (check_targetable(pos+mov[i],unitType,u.health,escape)) {
            //FOUND
            m.insert(make_pair(pos+mov[i],pos));
            Pos pos_dir = pos+mov[i];
            Pos pos_aux;
            while (pos_dir != u.pos) {
              pos_aux = pos_dir;
              pos_dir = m[pos_dir];
            }
            already_moved.insert(pos_aux);
            //already_targeted.insert(pos_aux);
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
            if (s_visited.find(pos+mov[i]) == s_visited.end()) {
              s_visited.insert(pos+mov[i]);
              q.push(pos+mov[i]);
              m.insert(make_pair(pos+mov[i],pos));
            }
          }
        }
      }
      if (first_pos)
        first_pos = false;
    }
    return false;
  }

  bool threatened(int id) {
    int health;
    Unit u = unit(id);
    if (u.type == Farmer and knighted(u.pos))
      return false;
    if (u.type == Knight and knighted2(u.pos,health) and health > u.health)
      return false;
    if (extra_haunted(u.pos))
      return false;
    return true;
  }

  void moveFarmer(int id) {
    bool b = bfs(id,NOT_ESCAPE_MAX);
    if (not b) {
      b = bfs(id,NOT_ESCAPE_MIN);
      if (not b) {
        if (threatened(id)) {
          b = bfs(id,ESCAPE);
          if (not b) {
            b = bfs(id,ESCAPE_FAILED_DO_SOMETHING);
            if (not b) {
              command(id,None);
            }
          }
        }
        else {
          command(id,None);
        }
      }
    }
  }

  void moveKnight(int id) {
    bool b = bfs(id,NOT_ESCAPE_MAX);
    if (not b) {
      b = bfs(id,NOT_ESCAPE_MIN);
      if (not b) {
        if (threatened(id)) {
          b = bfs(id,ESCAPE);
          if (not b) {
            b = bfs(id,ESCAPE_FAILED_DO_SOMETHING);
            if (not b) {
              command(id,None);
            }
          }
        }
        else {
          command(id,None);
        }
      }
    }
  }

  void moveWitch(int id) {
    bool b = bfs(id,NOT_ESCAPE_MAX);
    if (not b) {
      bool b = bfs(id,NOT_ESCAPE_MIN);
      if (not b)
        command(id,None);
    }
    
  }

  void moveAllFarmers() {
    f = farmers(0);
    for (int i = 0; i < f.size(); i++)
      moveFarmer(f[i]);
  }

  void moveAllKnights() {
    k = knights(0);
    for (int i = 0; i < k.size(); i++)
      moveKnight(k[i]);
  }

  void moveAllWitches() {
    w = witches(0);
    for (int i = 0; i < w.size(); i++)
      moveWitch(w[i]);
  }

  void moveAllUnits() {
    moveAllWitches();
    moveAllKnights();
    moveAllFarmers();
  }

  /**
   * Types and attributes for your player can be defined here.
   */

  vector<int> f;
  vector<int> k;
  vector<int> w;
  Dir movements[8] = {Left,Top,Right,Bottom,BR,RT,TL,LB};
  set<Pos> already_moved;
  //set<Pos> already_targeted;

  /**
   * Play method, invoked once per each round.
   */

  virtual void play () {
    already_moved.clear();
    //already_targeted.clear();
    moveAllUnits();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
