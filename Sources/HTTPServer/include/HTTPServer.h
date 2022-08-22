#ifndef HTTPServer_H
#define HTTPServer_H

#import <Foundation/Foundation.h>
#import <CFNetwork/CFNetwork.h>

@class HTTPServer, HTTPConnection, HTTPMessage;
@protocol HTTPResponse;

@interface HTTPConfig : NSObject
- (id)initWithServer:(HTTPServer *)server documentRoot:(NSString *)documentRoot;
- (id)initWithServer:(HTTPServer *)server documentRoot:(NSString *)documentRoot queue:(dispatch_queue_t)q;
@property (nonatomic, unsafe_unretained, readonly) HTTPServer *server;
@property (nonatomic, strong, readonly) NSString *documentRoot;
@property (nonatomic, readonly) dispatch_queue_t queue;
@end

@interface GCDAsyncSocket: NSObject
- (id)init;
- (id)initWithSocketQueue:(dispatch_queue_t)sq;
- (id)initWithDelegate:(id)aDelegate delegateQueue:(dispatch_queue_t)dq;
- (id)initWithDelegate:(id)aDelegate delegateQueue:(dispatch_queue_t)dq socketQueue:(dispatch_queue_t)sq;
- (id)delegate;
- (void)setDelegate:(id)delegate;
- (void)synchronouslySetDelegate:(id)delegate;
- (dispatch_queue_t)delegateQueue;
- (void)setDelegateQueue:(dispatch_queue_t)delegateQueue;
- (void)synchronouslySetDelegateQueue:(dispatch_queue_t)delegateQueue;
- (void)getDelegate:(id *)delegatePtr delegateQueue:(dispatch_queue_t *)delegateQueuePtr;
- (void)setDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)synchronouslySetDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (BOOL)isIPv4Enabled;
- (void)setIPv4Enabled:(BOOL)flag;
- (BOOL)isIPv6Enabled;
- (void)setIPv6Enabled:(BOOL)flag;
- (BOOL)isIPv4PreferredOverIPv6;
- (void)setPreferIPv4OverIPv6:(BOOL)flag;
- (int)receiveBufferSize;
- (void)setReceiveBufferSize:(int)bufferSize;
- (id)userData;
- (void)setUserData:(id)arbitraryUserData;
- (UInt64)countedBytesWritten;
- (void)resetCountedBytesWritten;
- (BOOL)acceptOnPort:(uint16_t)port error:(NSError **)errPtr;
- (BOOL)acceptOnInterface:(NSString *)interface port:(uint16_t)port error:(NSError **)errPtr;
- (BOOL)acceptOnIPv4Socket:(int)sd4 IPv6Socket:(int)sd6 unixSocket:(int)sdu error:(NSError **)errPtr;
- (BOOL)connectToHost:(NSString *)host onPort:(uint16_t)port error:(NSError **)errPtr;
- (BOOL)connectToHost:(NSString *)host
               onPort:(uint16_t)port
          withTimeout:(NSTimeInterval)timeout
                error:(NSError **)errPtr;
- (BOOL)connectToHost:(NSString *)host
               onPort:(uint16_t)port
         viaInterface:(NSString *)interface
          withTimeout:(NSTimeInterval)timeout
                error:(NSError **)errPtr;
- (BOOL)connectToAddress:(NSData *)remoteAddr error:(NSError **)errPtr;
- (BOOL)connectToAddress:(NSData *)remoteAddr withTimeout:(NSTimeInterval)timeout error:(NSError **)errPtr;
- (BOOL)connectToAddress:(NSData *)remoteAddr
            viaInterface:(NSString *)interface
             withTimeout:(NSTimeInterval)timeout
                   error:(NSError **)errPtr;
- (void)disconnect;
- (void)disconnectAfterReading;
- (void)disconnectAfterWriting;
- (void)disconnectAfterReadingAndWriting;
- (BOOL)isDisconnected;
- (BOOL)isConnected;
- (NSString *)connectedHost;
- (uint16_t)connectedPort;
- (NSString *)localHost;
- (uint16_t)localPort;
- (NSData *)connectedAddress;
- (NSData *)localAddress;
- (NSArray *)localAddresses;
- (BOOL)isIPv4;
- (BOOL)isIPv6;
- (BOOL)isSecure;
- (void)readDataWithTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)readDataWithTimeout:(NSTimeInterval)timeout
                     buffer:(NSMutableData *)buffer
               bufferOffset:(NSUInteger)offset
                        tag:(long)tag;
- (void)readDataWithTimeout:(NSTimeInterval)timeout
                     buffer:(NSMutableData *)buffer
               bufferOffset:(NSUInteger)offset
                  maxLength:(NSUInteger)length
                        tag:(long)tag;
- (void)readDataToLength:(NSUInteger)length withTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)readDataToLength:(NSUInteger)length
             withTimeout:(NSTimeInterval)timeout
                  buffer:(NSMutableData *)buffer
            bufferOffset:(NSUInteger)offset
                     tag:(long)tag;
- (void)readDataToData:(NSData *)data withTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)readDataToData:(NSData *)data
           withTimeout:(NSTimeInterval)timeout
                buffer:(NSMutableData *)buffer
          bufferOffset:(NSUInteger)offset
                   tag:(long)tag;
- (void)readDataToData:(NSData *)data withTimeout:(NSTimeInterval)timeout maxLength:(NSUInteger)length tag:(long)tag;
- (void)readDataToData:(NSData *)data
           withTimeout:(NSTimeInterval)timeout
                buffer:(NSMutableData *)buffer
          bufferOffset:(NSUInteger)offset
             maxLength:(NSUInteger)length
                   tag:(long)tag;
- (float)progressOfReadReturningTag:(long *)tagPtr bytesDone:(NSUInteger *)donePtr total:(NSUInteger *)totalPtr;
- (void)writeData:(NSData *)data withTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)writeData:(NSData *)data withTimeout:(NSTimeInterval)timeout tag:(long)tag countBytesWritten:(BOOL)countBytesWritten;
- (void)writeSendfile:(NSFileHandle *)file atOffset:(off_t)offset andLength:(off_t)length withTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)writeSendfile:(NSFileHandle *)file atOffset:(off_t)offset andLength:(off_t)length withTimeout:(NSTimeInterval)timeout tag:(long)tag countBytesWritten:(BOOL)countBytesWritten;
- (float)progressOfWriteReturningTag:(long *)tagPtr bytesDone:(NSUInteger *)donePtr total:(NSUInteger *)totalPtr;
- (void)startTLS:(NSDictionary *)tlsSettings;
- (BOOL)autoDisconnectOnClosedReadStream;
- (void)setAutoDisconnectOnClosedReadStream:(BOOL)flag;
- (void)markSocketQueueTargetQueue:(dispatch_queue_t)socketQueuesPreConfiguredTargetQueue;
- (void)unmarkSocketQueueTargetQueue:(dispatch_queue_t)socketQueuesPreviouslyConfiguredTargetQueue;
- (void)performBlock:(dispatch_block_t)block;
- (int)socketFD;
- (int)socket4FD;
- (int)socket6FD;
+ (NSString *)hostFromAddress:(NSData *)address;
+ (uint16_t)portFromAddress:(NSData *)address;
+ (BOOL)getHost:(NSString **)hostPtr port:(uint16_t *)portPtr fromAddress:(NSData *)address;
+ (NSData *)CRLFData;
+ (NSData *)CRData;
+ (NSData *)LFData;
+ (NSData *)ZeroData;
@end

@protocol GCDAsyncSocketDelegate
@optional
- (dispatch_queue_t)newSocketQueueForConnectionFromAddress:(NSData *)address onSocket:(GCDAsyncSocket *)sock;
- (void)socket:(GCDAsyncSocket *)sock didAcceptNewSocket:(GCDAsyncSocket *)newSocket;
- (void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port;
- (void)socket:(GCDAsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag;
- (void)socket:(GCDAsyncSocket *)sock didReadPartialDataOfLength:(NSUInteger)partialLength tag:(long)tag;
- (void)socket:(GCDAsyncSocket *)sock didWriteDataWithTag:(long)tag;
- (void)socket:(GCDAsyncSocket *)sock didWritePartialDataOfLength:(NSUInteger)partialLength tag:(long)tag;
- (NSTimeInterval)socket:(GCDAsyncSocket *)sock shouldTimeoutReadWithTag:(long)tag
                                                                 elapsed:(NSTimeInterval)elapsed
                                                               bytesDone:(NSUInteger)length;
- (NSTimeInterval)socket:(GCDAsyncSocket *)sock shouldTimeoutWriteWithTag:(long)tag
                                                                  elapsed:(NSTimeInterval)elapsed
                                                                bytesDone:(NSUInteger)length;
- (void)socketDidCloseReadStream:(GCDAsyncSocket *)sock;
- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)err;
- (void)socketDidSecure:(GCDAsyncSocket *)sock;
@end

@interface HTTPConnection : NSObject
- (id)initWithAsyncSocket:(GCDAsyncSocket *)newSocket configuration:(HTTPConfig *)aConfig;
- (void)start;
- (void)stop;
- (void)stopAfterResponding;
- (void)startConnection;
- (BOOL)supportsMethod:(NSString *)method atPath:(NSString *)path;
- (BOOL)expectsRequestBodyFromMethod:(NSString *)method atPath:(NSString *)path;
- (BOOL)expectsDelayedResponse;
- (BOOL)supportsStreamedRequestBody;
- (BOOL)isSecureServer;
- (NSArray *)sslIdentityAndCertificates;
- (const SSLCipherSuite *)sslCipherSuites:(size_t *)count_r;
- (void)customizeSSLSettings:(NSMutableDictionary *)settings;
- (BOOL)isPasswordProtected:(NSString *)path;
- (BOOL)useDigestAccessAuthentication;
- (NSString *)realm;
- (NSString *)passwordForUser:(NSString *)username;
- (NSDictionary *)parseParams:(NSString *)query;
+ (NSDictionary *)parseParams:(NSString *)query;
- (NSDictionary *)parseGetParams;
- (NSString *)requestURI;
- (NSArray *)directoryIndexFileNames;
- (NSString *)filePathForURI:(NSString *)path;
- (NSString *)filePathForURI:(NSString *)path allowDirectory:(BOOL)allowDirectory;
- (NSObject<HTTPResponse> *)httpResponseForMethod:(NSString *)method URI:(NSString *)path;
- (void)startResponseForMethod:(NSString *)method URI:(NSString *)path;
- (NSString *)connectedHost;
- (uint16_t)connectedPort;
- (NSUInteger)requestBodyChunkSize;
- (BOOL)shouldReadMoreBodyDataNow;
- (void)readMoreBodyDataNow;
- (void)prepareForBodyWithSize:(UInt64)contentLength;
- (void)processBodyData:(NSData *)postDataChunk;
- (void)finishBody;
- (int)receiveBufferSize;
- (void)setReceiveBufferSize:(int)bufferSize;

- (void)handleVersionNotSupported:(NSString *)version;
- (void)handleAuthenticationFailed;
- (void)handleResourceNotFound;
- (void)handleInvalidRequest:(NSData *)data;
- (void)handleUnknownMethod:(NSString *)method;
- (void)handleNotImplemented;
- (void)handleNotAvailable;
- (void)handleInternalServerError;
- (NSData *)preprocessResponse:(HTTPMessage *)response;
- (NSData *)preprocessErrorResponse:(HTTPMessage *)response;
- (void)finishResponse;
- (BOOL)shouldDie;
- (void)die;
- (UInt64)bodyBytesWritten;
- (void)resetBodyBytesWritten;
- (NSURL *)url;
@end

@interface HTTPConnection (AsynchronousHTTPResponse)
- (void)responseHasAvailableData:(NSObject<HTTPResponse> *)sender;
- (void)responseDidAbort:(NSObject<HTTPResponse> *)sender;
@end

@interface HTTPData : NSObject
@property (readonly)NSUInteger length;
- (id)initWithSendfile:(NSFileHandle *)aFile offset:(off_t)aOffset length:(off_t)aLength;
- (id)initWithData:(NSData *)aData;
@end

@protocol HTTPResponse
- (UInt64)contentLength;
- (UInt64)offset;
- (void)setOffset:(UInt64)offset;
- (BOOL)isDone;
@optional
- (NSData *)readDataOfLength:(NSUInteger)length;
- (HTTPData *)readHTTPDataOfLength:(NSUInteger)length orLimit:(NSUInteger)limit;
- (BOOL)delayResponseHeaders;
- (NSInteger)status;
- (NSDictionary *)httpHeaders;
- (BOOL)isChunked;
- (void)connectionDidClose;
@end

@interface HTTPDataResponse : NSObject <HTTPResponse>
- (id)initWithData:(NSData *)data;
@end

@interface HTTPErrorResponse : NSObject <HTTPResponse>
- (id)initWithErrorCode:(int)httpErrorCode;
@end

@interface HTTPRedirectResponse : NSObject <HTTPResponse>
- (id)initWithPath:(NSString *)redirectPath;
@end

@interface HTTPFileResponse : NSObject <HTTPResponse>
- (id)initWithFilePath:(NSString *)filePath forConnection:(HTTPConnection *)connection;
- (NSString *)filePath;
@end

@interface HTTPSendFileResponse : NSObject <HTTPResponse>
- (id)initWithFilePath:(NSString *)filePath forConnection:(HTTPConnection *)connection;
- (NSString *)filePath;
@end

@interface HTTPAsyncFileResponse : NSObject <HTTPResponse>
- (id)initWithFilePath:(NSString *)filePath forConnection:(HTTPConnection *)connection;
- (NSString *)filePath;
@end

@interface NSData (DDData)
- (NSData *)md5Digest;
- (NSData *)sha1Digest;
- (NSString *)hexStringValue;
- (NSString *)base64Encoded;
- (NSData *)base64Decoded;
@end

@interface HTTPMessage : NSObject
@property (readonly)CFHTTPMessageRef message;
- (id)initEmptyRequest;
- (id)initRequestWithMethod:(NSString *)method URL:(NSURL *)url version:(NSString *)version;
- (id)initResponseWithStatusCode:(NSInteger)code description:(NSString *)description version:(NSString *)version;
- (BOOL)appendData:(NSData *)data;
- (BOOL)isHeaderComplete;
- (NSString *)version;
- (NSString *)method;
- (NSURL *)url;
- (NSInteger)statusCode;
- (NSDictionary *)allHeaderFields;
- (NSString *)headerField:(NSString *)headerField;
- (void)setHeaderField:(NSString *)headerField value:(NSString *)headerFieldValue;
- (NSData *)messageData;
- (NSData *)body;
- (void)setBody:(NSData *)body;
@end


@interface HTTPServer : NSObject <NSNetServiceDelegate>
- (Class)connectionClass;
- (void)setConnectionClass:(Class)value;
- (NSString *)interface;
- (void)setInterface:(NSString *)value;
- (NSArray *)listeningAddresses;
- (UInt16)port;
- (UInt16)listeningPort;
- (void)setPort:(UInt16)value;
- (NSString *)domain;
- (void)setDomain:(NSString *)value;
- (NSString *)name;
- (NSString *)publishedName;
- (void)setName:(NSString *)value;
- (NSString *)type;
- (void)setType:(NSString *)value;
- (void)republishBonjour;
- (NSDictionary *)TXTRecordDictionary;
- (void)setTXTRecordDictionary:(NSDictionary *)dict;
- (int)listeningIPv4Socket;
- (void)setListeningIPv4Socket:(int)sd;
- (int)listeningIPv6Socket;
- (void)setListeningIPv6Socket:(int)sd;
- (int)listeningUnixSocket;
- (void)setListeningUnixSocket:(int)sd;
- (BOOL)start:(NSError **)errPtr;
- (void)stop;
- (void)stop:(BOOL)keepExistingConnections;
- (BOOL)isRunning;
- (NSUInteger)numberOfHTTPConnections;
@end

#endif /* #ifndef HTTPServer_H */
