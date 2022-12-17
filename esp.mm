#import <Foundation/Foundation.h>
#import "esp.h"
#import <UIKit/UIKit.h>

@implementation esp : UIView
@synthesize players;
@synthesize espboxes;
@synthesize esplines;
@synthesize healthbarr;
@synthesize distanceesp;
@synthesize crouchknocked;


- (id)initWithFrame:(UIWindow*)main
{
    self = [super initWithFrame:main.frame];
    self.userInteractionEnabled = false;
    self.hidden = false;
    self.backgroundColor = [UIColor clearColor];
    if(!players){
        players = new std::vector<player_t *>();
    }
    [main addSubview:self];
    return self;
}
- (void)Update {
    [self setNeedsDisplay];
}
- (void)drawRect:(CGRect)rect {
    CGContextRef contextRef = UIGraphicsGetCurrentContext();
    CGContextClearRect(contextRef,self.bounds);
    CGContextSetLineWidth(contextRef, 0.5);
    CGColor *colour;
    UIColor *Ucolour;
    for(int i = 0; i < players->size(); i++) {
        if((*players)[i]->enemy){
			if((*players)[i]->distance < 50) {
				colour = [UIColor redColor].CGColor;
				Ucolour = [UIColor redColor];
			}
			else if((*players)[i]->distance >= 50 && (*players)[i]->distance <= 150){
				colour = [UIColor yellowColor].CGColor;
				Ucolour = [UIColor yellowColor];
			}
			else {
				colour = [UIColor greenColor].CGColor;
				Ucolour = [UIColor greenColor];
			}
        }else{
            colour = [UIColor blueColor].CGColor;
            Ucolour = [UIColor blueColor];
        }
        CGContextSetStrokeColorWithColor(contextRef, colour);
        if(esplines){
            if((*players)[i]->enemy){
                CGContextMoveToPoint(contextRef,self.frame.size.width/2, self.frame.size.height);
                CGContextAddLineToPoint(contextRef, (*players)[i]->bottomofbox.x, (*players)[i]->bottomofbox.y);
            }else{
                CGContextMoveToPoint(contextRef,self.frame.size.width/2, self.frame.size.height);
                CGContextAddLineToPoint(contextRef, (*players)[i]->bottomofbox.x, (*players)[i]->bottomofbox.y);
            }
            CGContextStrokePath(contextRef);
        }
        if(espboxes){
            CGContextStrokeRect(contextRef, (*players)[i]->box);
        }
        if(healthbarr){
            [[UIColor redColor] setFill];
            CGContextFillRect(contextRef, (*players)[i]->healthbar);
            [[UIColor greenColor] setFill];
            float cc = (*players)[i]->health/100;
            CGRect healthbar = CGRectMake((*players)[i]->healthbar.origin.x, (*players)[i]->healthbar.origin.y, (*players)[i]->healthbar.size.width, (*players)[i]->healthbar.size.height*cc);
            CGContextFillRect(contextRef, healthbar);
        }
        if(distanceesp){
            NSString *text = [NSString stringWithFormat:@"%.0f", (*players)[i]->distance];
            float xd = 30 / ((*players)[i]->distance/10);
            if(xd>25){
                xd = 25.0f;
            }
            xd = 5;
            NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:xd], NSForegroundColorAttributeName:Ucolour};
            [text drawAtPoint:CGPointMake(((*players)[i]->bottomofbox.x), ((*players)[i]->bottomofbox.y)) withAttributes:attributes];
        }
		if(crouchknocked){
            NSString *text = [NSString stringWithFormat:@"%s", (*players)[i]->crouch_knocked.c_str()];
            float xd = 30 / ((*players)[i]->distance/10);
            if(xd>25){
                xd = 25.0f;
            }
            xd = 12.5;
            NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:xd], NSForegroundColorAttributeName:Ucolour};
            [text drawAtPoint:CGPointMake(((*players)[i]->box.origin.x + ((*players)[i]->box.size.width)*2), ((*players)[i]->topofbox.y) + (*players)[i]->box.size.width) withAttributes:attributes];
		}
	} 
}



@end