//
//  MCOAddress.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 3/10/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __MAILCORE_MCOADDRESS_H_

#define __MAILCORE_MCOADDRESS_H_

#import <Foundation/Foundation.h>

@interface MCOAddress : NSObject <NSCopying>

// Creates an address with a display name and a mailbox.
// Example: [MCOAddress addressWithDisplayName:@"DINH Viêt Hoà" mailbox:@"hoa@etpan.org"]
+ (MCOAddress *) addressWithDisplayName:(NSString *)displayName
                                mailbox:(NSString *)mailbox;

// Creates an address with only a mailbox.
// Example: [MCOAddress addressWithMailbox:@"hoa@etpan.org"]
+ (MCOAddress *) addressWithMailbox:(NSString *)mailbox;

// Creates an address with a RFC822 string.
// Example: [MCOAddress addressWithRFC822String:@"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"]
+ (MCOAddress *) addressWithRFC822String:(NSString *)RFC822String;

// Creates an address with a non-MIME-encoded RFC822 string.
// Example: [MCOAddress addressWithRFC822String:@"DINH Viêt Hoà <hoa@etpan.org>"]
+ (MCOAddress *) addressWithNonEncodedRFC822String:(NSString *)nonEncodedRFC822String;

// Returns the display name of the address.
@property (nonatomic, copy) NSString * displayName;

// Returns the mailbox of the address.
@property (nonatomic, copy) NSString * mailbox;

// Returns the RFC822 encoding of the address.
// For example: "DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"
- (NSString *) RFC822String;

// Returns the non-MIME-encoded RFC822 encoding of the address.
// For example: "DINH Viêt Hoà <hoa@etpan.org>"
- (NSString *) nonEncodedRFC822String;

@end

@interface MCOAddress (MCONSArray)

// Returns an NSArray of MCOAddress objects that contain the parsed
// forms of the RFC822 encoded addresses.
// For example: @[ @"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>" ]
+ (NSArray *) addressesWithRFC822String:(NSString *)string;

// Returns an NSArray of MCOAddress objects that contain the parsed
// forms of non-encoded RFC822 addresses.
// For example: @[ "DINH Viêt Hoà <hoa@etpan.org>" ]
+ (NSArray *) addressesWithNonEncodedRFC822String:(NSString *)string;

@end

@interface NSArray (MCONSArray)

// The receiver is an NSArray of MCOAddress.
// Returns an NSArray of NSString objects separated by commas that contain the
// RFC822 encoding of the addresses.
// For example: @[ @"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>" ]
- (NSString *) RFC822String;

// Returns an NSArray of NSString objects separated by commas that contain the
// non-MIME-encoded RFC822 form of the addresses.
// For example: @[ "DINH Viêt Hoà <hoa@etpan.org>" ]
- (NSString *) nonEncodedRFC822String;

@end

#endif
