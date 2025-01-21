// problem : https://leetcode.com/problems/min-stack/
// time complexity  -> O(1)   ; for getMin()
// space complexity -> O(1)

#define STACKSIZE  100000

  typedef struct {
    // each element has a mval, which holds the min val encounterd till now
    // so the element in top will have the min val till latest
    int val;
    int mval;
  } element;

  typedef struct {
    element *items;
    int top;
  } MinStack;


  MinStack* minStackCreate() {
    MinStack *ms = malloc(sizeof(MinStack));
    ms->items = malloc(STACKSIZE * sizeof(element));
    ms->top = -1;
    return ms;    
  }

  void minStackFree(MinStack* obj) {
    free(obj->items);
    free(obj);    
  }

  void minStackPush(MinStack* obj, int val) {
    int last_min = INT_MIN;

    // if its not a first element, we need to calcualte the min
    if (obj->top >= 0) {
      last_min = obj->items[obj->top].mval;
      last_min = val < last_min ? val : last_min;
    }

    obj->top++;
    obj->items[obj->top].val = val;
    obj->items[obj->top].mval = last_min == INT_MIN ? val : last_min;
  }

  void minStackPop(MinStack* obj) {
    obj->top--;    
  }

  int minStackTop(MinStack* obj) {
    return obj->items[obj->top].val;
  }

  int minStackGetMin(MinStack* obj) {
      return obj->items[obj->top].mval;
  }



  /**
  * Your MinStack struct will be instantiated and called as such:
  * MinStack* obj = minStackCreate();
  * minStackPush(obj, val);
  
  * minStackPop(obj);
  
  * int param_3 = minStackTop(obj);
  
  * int param_4 = minStackGetMin(obj);
  
  * minStackFree(obj);
  */
