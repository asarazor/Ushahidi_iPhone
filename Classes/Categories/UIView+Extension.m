/*****************************************************************************
 ** Copyright (c) 2010 Ushahidi Inc
 ** All rights reserved
 ** Contact: team@ushahidi.com
 ** Website: http://www.ushahidi.com
 **
 ** GNU Lesser General Public License Usage
 ** This file may be used under the terms of the GNU Lesser
 ** General Public License version 3 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file. Please review the following information to
 ** ensure the GNU Lesser General Public License version 3 requirements
 ** will be met: http://www.gnu.org/licenses/lgpl.html.
 **
 **
 ** If you have questions regarding the use of this file, please contact
 ** Ushahidi developers at team@ushahidi.com.
 **
 *****************************************************************************/

#import "UIView+Extension.h"

@implementation UIView (Extension)

- (UIView *)findFirstResponder {
    if (self.isFirstResponder) {        
        return self;     
    }
    for (UIView *subView in self.subviews) {
        UIView *firstResponder = [subView findFirstResponder];
        if (firstResponder != nil) {
            return firstResponder;
        }
    }	
    return nil;
}

- (void) setFrameWidth:(CGFloat)frameWidth {
	CGRect rect = self.frame;
	rect.size.width = frameWidth;
	self.frame = rect;
}

- (void) setFrameHeight:(CGFloat)height {
	CGRect rect = self.frame;
	rect.size.height = height;
	self.frame = rect;
}

@end
