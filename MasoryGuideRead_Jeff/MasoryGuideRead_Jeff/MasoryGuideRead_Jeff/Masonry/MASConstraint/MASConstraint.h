//
//  MASConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//
/*
 - (MASConstraint * (^)(MASEdgeInsets insets))insets;    //设置 edge
 - (MASConstraint * (^)(CGSize offset))sizeOffset;       //直接设置控件的宽高
 - (MASConstraint * (^)(CGPoint offset))centerOffset;    //接收CGPoint结构的偏移量
 - (MASConstraint * (^)(CGFloat offset))offset;          //普通的偏移
 
 - (MASConstraint * (^)(NSValue *value))valueOffset;     //会根据value类型自动转化成上面的值
 --------
 
 - (MASConstraint * (^)(CGFloat multiplier))multipliedBy;
 - (MASConstraint * (^)(CGFloat divider))dividedBy;      // 1/dividedBy = multipliedBy
 
 - (MASConstraint * (^)(MASLayoutPriority priority))priority;    //可具体设置优先级
 - (MASConstraint * (^)())priorityLow;
 - (MASConstraint * (^)())priorityMedium;
 - (MASConstraint * (^)())priorityHigh;
 
 - (MASConstraint * (^)(id attr))equalTo;
 - (MASConstraint * (^)(id attr))greaterThanOrEqualTo;
 - (MASConstraint * (^)(id attr))lessThanOrEqualTo;
 
 - (MASConstraint *)with;
 - (MASConstraint *)and;
 
 - (MASConstraint *)left;
。。。。。。
 - (MASConstraint *)baseline;
 
 - (MASConstraint *)firstBaseline;
 - (MASConstraint *)lastBaseline;
 
 - (MASConstraint *)leftMargin;
。。。。。。
 - (MASConstraint *)centerYWithinMargins;
 
 - (MASConstraint * (^)(id key))key;
 
 //可以手动设置 inset等熟悉。上面的点语法内部其实就是调用这个方法。
 - (void)setInsets:(MASEdgeInsets)insets;
 - (void)setSizeOffset:(CGSize)sizeOffset;
 - (void)setCenterOffset:(CGPoint)centerOffset;
 - (void)setOffset:(CGFloat)offset;
 
 @property (nonatomic, copy, readonly) MASConstraint *animator;
 
 - (void)activate;       //和install差不多的接口
 - (void)deactivate;     //使之前的约束都失效
 
 - (void)install;
 - (void)uninstall;
 
 */

#import "MASUtilities.h"

/**
 *	Enables Constraints to be created with chainable syntax
 *  Constraint can represent single NSLayoutConstraint (MASViewConstraint) 
 *  or a group of NSLayoutConstraints (MASComposisteConstraint)
 */
@interface MASConstraint : NSObject



// Chaining Support

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (MASConstraint * (^)(MASEdgeInsets insets))insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (MASConstraint * (^)(CGSize offset))sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (MASConstraint * (^)(CGPoint offset))centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (MASConstraint * (^)(CGFloat offset))offset;

/**
 *  Modifies the NSLayoutConstraint constant based on a value type
 */
- (MASConstraint * (^)(NSValue *value))valueOffset;

/**
 *	Sets the NSLayoutConstraint multiplier property
 */
- (MASConstraint * (^)(CGFloat multiplier))multipliedBy;

/**
 *	Sets the NSLayoutConstraint multiplier to 1.0/dividedBy
 */
- (MASConstraint * (^)(CGFloat divider))dividedBy;

/**
 *	Sets the NSLayoutConstraint priority to a float or MASLayoutPriority
 */
- (MASConstraint * (^)(MASLayoutPriority priority))priority;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityLow
 */
- (MASConstraint * (^)())priorityLow;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityMedium
 */
- (MASConstraint * (^)())priorityMedium;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityHigh
 */
- (MASConstraint * (^)())priorityHigh;

/**
 *	Sets the constraint relation to NSLayoutRelationEqual
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (MASConstraint * (^)(id attr))equalTo;

/**
 *	Sets the constraint relation to NSLayoutRelationGreaterThanOrEqual
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (MASConstraint * (^)(id attr))greaterThanOrEqualTo;

/**
 *	Sets the constraint relation to NSLayoutRelationLessThanOrEqual
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (MASConstraint * (^)(id attr))lessThanOrEqualTo;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (MASConstraint *)with;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (MASConstraint *)and;

/**
 *	Creates a new MASCompositeConstraint with the called attribute and reciever
 */
- (MASConstraint *)left;
- (MASConstraint *)top;
- (MASConstraint *)right;
- (MASConstraint *)bottom;
- (MASConstraint *)leading;
- (MASConstraint *)trailing;
- (MASConstraint *)width;
- (MASConstraint *)height;
- (MASConstraint *)centerX;
- (MASConstraint *)centerY;
- (MASConstraint *)baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

- (MASConstraint *)firstBaseline;
- (MASConstraint *)lastBaseline;

#endif

#if TARGET_OS_IPHONE || TARGET_OS_TV

- (MASConstraint *)leftMargin;
- (MASConstraint *)rightMargin;
- (MASConstraint *)topMargin;
- (MASConstraint *)bottomMargin;
- (MASConstraint *)leadingMargin;
- (MASConstraint *)trailingMargin;
- (MASConstraint *)centerXWithinMargins;
- (MASConstraint *)centerYWithinMargins;

#endif


/**
 *	Sets the constraint debug name
 */
- (MASConstraint * (^)(id key))key;

// NSLayoutConstraint constant Setters
// for use outside of mas_updateConstraints/mas_makeConstraints blocks

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInsets:(MASEdgeInsets)insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (void)setSizeOffset:(CGSize)sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (void)setCenterOffset:(CGPoint)centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (void)setOffset:(CGFloat)offset;


// NSLayoutConstraint Installation support

#if TARGET_OS_MAC && !(TARGET_OS_IPHONE || TARGET_OS_TV)
/**
 *  Whether or not to go through the animator proxy when modifying the constraint
 */
@property (nonatomic, copy, readonly) MASConstraint *animator;
#endif


/**
 *  Activates an NSLayoutConstraint if it's supported by an OS. 
 *  Invokes install otherwise.
 */
- (void)activate;

/**
 *  Deactivates previously installed/activated NSLayoutConstraint.
 */
- (void)deactivate;

/**
 *	Creates a NSLayoutConstraint and adds it to the appropriate view.
 */
- (void)install;

/**
 *	Removes previously installed NSLayoutConstraint
 */
- (void)uninstall;

@end


/**
 *  Convenience auto-boxing macros for MASConstraint methods.
 *
 *  Defining MAS_SHORTHAND_GLOBALS will turn on auto-boxing for default syntax.
 *  A potential drawback of this is that the unprefixed macros will appear in global scope.
 */
#define mas_equalTo(...)                 equalTo(MASBoxValue((__VA_ARGS__)))
#define mas_greaterThanOrEqualTo(...)    greaterThanOrEqualTo(MASBoxValue((__VA_ARGS__)))
#define mas_lessThanOrEqualTo(...)       lessThanOrEqualTo(MASBoxValue((__VA_ARGS__)))

#define mas_offset(...)                  valueOffset(MASBoxValue((__VA_ARGS__)))


#ifdef MAS_SHORTHAND_GLOBALS

#define equalTo(...)                     mas_equalTo(__VA_ARGS__)
#define greaterThanOrEqualTo(...)        mas_greaterThanOrEqualTo(__VA_ARGS__)
#define lessThanOrEqualTo(...)           mas_lessThanOrEqualTo(__VA_ARGS__)

#define offset(...)                      mas_offset(__VA_ARGS__)

#endif


@interface MASConstraint (AutoboxingSupport)

/**
 *  Aliases to corresponding relation methods (for shorthand macros)
 *  Also needed to aid autocompletion
 */
- (MASConstraint * (^)(id attr))mas_equalTo;
- (MASConstraint * (^)(id attr))mas_greaterThanOrEqualTo;
- (MASConstraint * (^)(id attr))mas_lessThanOrEqualTo;

/**
 *  A dummy method to aid autocompletion
 */
- (MASConstraint * (^)(id offset))mas_offset;

@end
