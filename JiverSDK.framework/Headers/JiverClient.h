//
//  JiverClient.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Jiver.h"
#import "JiverChannel.h"
#import "JiverMessage.h"
#import "JiverSystemMessage.h"
#import "JiverFileLink.h"
#import "JiverWSClient.h"
#import "JiverAPIClient.h"
#import "JiverCommand.h"
#import "JiverBroadcastMessage.h"
#import "JiverMessagingChannel.h"
#import "JiverReadStatus.h"
#import "JiverTypeStatus.h"
#import "JiverError.h"
#import "JiverMember.h"
#import "JiverWSClient.h"

void (^onMessageReceived)(JiverMessage *message);
void (^onSystemMessageReceived)(JiverSystemMessage *message);
void (^onBroadcastMessageReceived)(JiverBroadcastMessage *message);
void (^onFileReceived)(JiverFileLink *fileLink);
void (^onMessagingStarted)(JiverMessagingChannel *channel);
void (^onMessagingUpdated)(JiverMessagingChannel *channel);
void (^onMessagingEnded)(JiverMessagingChannel *channel);
void (^onReadReceived)(JiverReadStatus *status);
void (^onTypeStartReceived)(JiverTypeStatus *status);
void (^onTypeEndReceived)(JiverTypeStatus *status);

@interface JiverClient : NSObject

enum JiverDataType;

- (id) initWithAppId:(NSString *)appId;
- (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(enum JiverDataType jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *messageId))messageDelivery;

- (NSString *) getUserID;
- (NSString *) getUserName;
//- (void) setLastMessageLimit:(int)limit;
- (void) setLoginInfoWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken andDeviceId:(NSString *)deviceId;
- (void) setChannelUrl:(NSString *)channelUrl;
- (NSString *) getChannelUrl;
- (JiverChannel *) getCurrentChannel;
- (void) connectWithMaxMessageTs:(long long)maxMessageTs;
- (void) cancelAll;
- (void) disconnect;
- (void) registerNotificationHandlerMessagingChannelUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingChannelUpdated;
- (void) unregisterNotificationHandlerMessagingChannelUpdatedBlock;
- (void) cmdMessage:(NSString *)message withData:(NSString *)data andMessageId:(NSString *)messageId;
- (void) markAsRead;
- (void) markAsReadForChannelUrl:(NSString *)channelUrl;
- (void) getChannelListInPage:(int)page withQuery:(NSString *)query withLimit:(int)limit resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) getMessagingListWithResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) messageListInChannelUrl:(NSString *)channelUrl withMessageTs:(long long)messageTs prevLimit:(int)prevLimit andNextLimit:(int)nextLimit include:(BOOL)include resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) leaveChannel:(NSString *)channelUrl;
- (void) uploadFile:(NSData *)file type:(NSString *)type size:(unsigned long)size customField:(NSString *)customField uploadBlock:(void (^)(JiverFileInfo *fileInfo, NSError *error))onUpload;
- (void) cmdFile:(JiverFileInfo *)fileInfo;
//- (void) saveCursor;
//- (long long) loadCursorWithChannelUrl:(NSString *)channelUrl;
- (void) setLastMessageMills:(long long)lastMessageMills;
- (long long) getLastMessageMills;
- (void) messageReceived:(JiverMessage *)msg;
- (void) systemMessageReceived:(JiverSystemMessage *)msg;
- (void) broadcastMessageReceived:(JiverBroadcastMessage *)msg;
- (void) fileReceived:(JiverFileLink *)fileLink;
- (void) messagingStarted:(JiverMessagingChannel *)channel;
- (void) messagingEnded:(JiverMessagingChannel *)channel;
- (void) typeStart:(JiverTypeStatus *)status;
- (void) typeEnd:(JiverTypeStatus *)status;
- (void) startMessagingWithGuestIds:(NSArray *)guestIds;
- (void) endMessagingWithChannelUrl:(NSString *)channelUrl;
- (void) hideMessagingWithChannelUrl:(NSString *)channelUrl;
- (void) cmdRead;
- (void) cmdTypeStart;
- (void) cmdTypeEnd;
//- (void) loadPrevMessagesWithLimit:(int)limit;
//- (void) loadPrevMessagesWithMinMessageId:(long long)minMessageId andLimit:(int)limit;
//- (void) loadNextMessagesWithLimit:(int)limit;
//- (void) loadNextMessagesWithMaxMessageId:(long long)maxMessageId andLimit:(int)limit;
//- (void) endCursorMode;
//- (BOOL) isCursorMode;
//- (void) startCursorModeWithCursor:(long long)cursor prevLimit:(int)prevLimit andNextLimit:(int)nextLimit;
//- (void) loadMessagesWithCursor:(long long)cursor prevLimit:(int)prevLimit andNextLimit:(int)nextLimit;
//- (void) loadMoreMessagesWithLimit:(int)limit;
- (void) getMemberListInChannel:(NSString *)channelUrl withPageNum:(int)page withQuery:(NSString *)query withLimit:(int)limit resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) getMessagingUnreadCountResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) joinMessagingWithChannelUrl:(NSString *)channelUrl;
- (void) inviteMessagingWithChannelUrl:(NSString *)channelUrl andGuestIds:(NSArray *)guestIds;
- (long long)getMaxMessageTs;
- (enum WSReadyState) connectState;
@end
