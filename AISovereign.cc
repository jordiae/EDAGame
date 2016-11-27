#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Sovereign


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  inline bool knighted(Pos pos) {
    for (int i = 0; i < 8; i++){
        Cell c = cell(pos+knight_movements[i]);
        if (c.id != -1) {
          Unit u = unit(c.id);
          if (u.player != 0 and u.type == Knight)
            return true;
        }
    }

   return false;
  }

  inline bool check_farmer(Pos pos) {
    Cell c = cell(pos);
    if (c.type == Wall)
        return false;
    if (c.haunted)
        return false;
    if (c.id != -1)
        return false;
    if (knighted(pos))
      return false;
    return true;
  }

    inline bool check_targetable(Pos pos) {
    Cell c = cell(pos);
    if (c.owner != 0)
      return true;
    else
      return false;
  }

 /*inline bool check_knight_targetable(Pos pos) {
    Cell c = cell(pos);
    if (c.id != -1 and unit(c.id).player != 0)
      return true;
    else
      return false;
  }

  inline bool check_knight(Pos pos) {
    Cell c = cell(pos);
    if (c.type == Wall)
        return false;
    if (c.haunted)
        return false;
    if (c.id != -1)
        return false;
    if (knighted(pos))
      return false;
    return true;
  }*/


  /*inline bool bfs_farmer(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < 4; i++) {
        if (check_farmer(pos+farmer_movements[i])) {
          if (check_targetable(pos+farmer_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+farmer_movements[i],pos));
            Pos pos_dir = pos+farmer_movements[i];
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
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+farmer_movements[i]) == s_visited.end()) {
              q.push(pos+farmer_movements[i]);
              m.insert(make_pair(pos+farmer_movements[i],pos));
            }
          }
        }
      }
    }
    command(id,None);
    return false;
  }*/
  inline bool bfs_farmer(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < 4; i++) {
        if (check_farmer(pos+farmer_movements[i])) {
          if (check_targetable(pos+farmer_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+farmer_movements[i],pos));
            Pos pos_dir = pos+farmer_movements[i];
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
            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+farmer_movements[i]) == s_visited.end()) {
              q.push(pos+farmer_movements[i]);
              m.insert(make_pair(pos+farmer_movements[i],pos));
            }
          }
        }
      }
    }
    command(id,None);
    return false;
  }  
/*
    inline bool bfs_knight(int id) {
    Unit u = unit(id);
    queue<Pos> q;
    q.push(u.pos);
    map<Pos,Pos> m; // path: key child, info parent
    m.insert(make_pair(u.pos,u.pos));
    int c = 0;
    set<Pos> s_visited;
    
    while (not q.empty()) {
      Pos pos = q.front(); 
      s_visited.insert(pos);
      q.pop();
      for(int i = 0; i < 8; i++) {
        if (check_knight(pos+knight_movements[i])) {
          if (check_knight_targetable(pos+knight_movements[i])) {
            //FOUND
            m.insert(make_pair(pos+knight_movements[i],pos));
            Pos pos_dir = pos+knight_movements[i];
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
            else if (u.pos+BR == pos_aux) {
              command(id,BR);
            }
            else if (u.pos+BR == pos_aux) {
              command(id,BR);
            }
            else if (u.pos+RT == pos_aux) {
              command(id,RT);
            }
            else if (u.pos+TL == pos_aux) {
              command(id,TL);
            }
            else if (u.pos+LB== pos_aux) {
              command(id,LB);
            }

            return true;
          }
          else {
            // if (m.find(pos+farmer_movements[i]) == m.end()) {
            if (s_visited.find(pos+knight_movements[i]) == s_visited.end()) {
              q.push(pos+knight_movements[i]);
              m.insert(make_pair(pos+knight_movements[i],pos));
            }
          }
        }
      }
    }
    command(id,None);
    return false;
  }  
*/
  /**
   * Types and attributes for your player can be defined here.
   */

  vector<int> f;
  vector<int> k;
  Dir knight_movements[8] = {Bottom,BR,Right,RT,Top,TL,Left,LB};
  Dir farmer_movements[4] = {Left,Top,Right,Bottom};

  /**
   * Play method, invoked once per each round.
   */

  virtual void play () {
    f = farmers(0);
    for (int i = 0; i < f.size(); i++)
        bfs_farmer(f[i]);
    /*k = knights(0);
    for (int i = 0; i < k.size(); i++)
        bfs_knight(f[i]);*/

  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
