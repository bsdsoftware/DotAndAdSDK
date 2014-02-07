//
//  DotAndAdUtility.h
//  ORMMA
//
//  Created by Lorenzo Canese on 11/15/12.
//
//

#import <Foundation/Foundation.h>

@interface DotAndAdUtility : NSObject

typedef enum{
    ORMMAStateNormal = 0,
    ORMMAStateExpanded = 1	
}ORMMAState;

typedef enum{
    DotAndAdPositionCornerTr = 0,
    DotAndAdPositionCornerTl = 1,
    DotAndAdPositionCornerBr = 2,
    DotAndAdPositionCornerBl = 3
}DotAndAdPositionCorner;

typedef enum{
    DotAndAdAnimationFadeIn = 0,
    DotAndAdAnimationFadeOut = 1,
    DotAndAdAnimationLeft = 2,
    DotAndAdAnimationRight = 3,
    DotAndAdAnimationTop = 4,
    DotAndAdAnimationBottom = 5,
    DotAndAdAnimationNo = 6
}DotAndAdAnimation;

+ (void) DLog: (NSString*) message;


- (NSString*) ormmaStateFromEnum: (ORMMAState) state;
- (ORMMAState) ormmaStateFromString: (NSString*) state;
- (NSString*) dotAndAdPositionCornerFromEnum: (DotAndAdPositionCorner) corner;
- (DotAndAdPositionCorner) dotAndAdPositionCornerFromString: (NSString*) corner;
- (NSString*) dotAndAdAnimationFromEnum: (DotAndAdAnimation) animation;
- (DotAndAdAnimation) dotAndAdAnimationFromString: (NSString*) animation;

@end
