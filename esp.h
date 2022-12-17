#import <vector>
#import <UIKit/UIKit.h>
#include <string>
using namespace std;
struct player_t {
    CGRect box;
    CGRect healthbar;
    CGPoint topofbox;
    CGPoint bottomofbox;
    float health;
    float distance;
    bool enemy;
    void* object;
    Vector3 head;
    string crouch_knocked;
};
@interface esp : UIView
@property bool crouchknocked;
@property bool espboxes;
@property bool esplines;
@property bool healthbarr;
@property bool distanceesp;
@property std::vector<player_t *> *players;
- (void)Update;
- (void)drawRect:(CGRect)rect;
- (id)initWithFrame:(UIWindow*)main;
@end
