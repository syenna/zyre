/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZyre.h"


///
//  Print properties of object
void QmlZyre::print () {
    zyre_print (self);
};

///
//  Return our node UUID string, after successful initialization
const QString QmlZyre::uuid () {
    return QString (zyre_uuid (self));
};

///
//  Return our node name, after successful initialization
const QString QmlZyre::name () {
    return QString (zyre_name (self));
};

///
//  Set node header; these are provided to other nodes during discovery
//  and come in each ENTER message.                                    
void QmlZyre::setHeader (const QString &name, const QString &format) {
    zyre_set_header (self, name.toUtf8().data(), "%s", format.toUtf8().data());
};

///
//  Set verbose mode; this tells the node to log all traffic as well as 
//  all major events.                                                   
void QmlZyre::setVerbose () {
    zyre_set_verbose (self);
};

///
//  Set UDP beacon discovery port; defaults to 5670, this call overrides 
//  that so you can create independent clusters on the same network, for 
//  e.g. development vs. production. Has no effect after zyre_start().   
void QmlZyre::setPort (int portNbr) {
    zyre_set_port (self, portNbr);
};

///
//  Set UDP beacon discovery interval, in milliseconds. Default is instant
//  beacon exploration followed by pinging every 1,000 msecs.             
void QmlZyre::setInterval (size_t interval) {
    zyre_set_interval (self, interval);
};

///
//  Set network interface for UDP beacons. If you do not set this, CZMQ will
//  choose an interface for you. On boxes with several interfaces you should
//  specify which one you want to use, or strange things can happen.        
void QmlZyre::setInterface (const QString &value) {
    zyre_set_interface (self, value.toUtf8().data());
};

///
//  By default, Zyre binds to an ephemeral TCP port and broadcasts the local 
//  host name using UDP beaconing. When you call this method, Zyre will use  
//  gossip discovery instead of UDP beaconing. You MUST set-up the gossip    
//  service separately using zyre_gossip_bind() and _connect(). Note that the
//  endpoint MUST be valid for both bind and connect operations. You can use 
//  inproc://, ipc://, or tcp:// transports (for tcp://, use an IP address   
//  that is meaningful to remote as well as local nodes). Returns 0 if       
//  the bind was successful, else -1.                                        
int QmlZyre::setEndpoint (const QString &format) {
    return zyre_set_endpoint (self, "%s", format.toUtf8().data());
};

///
//  Set-up gossip discovery of other nodes. At least one node in the cluster
//  must bind to a well-known gossip endpoint, so other nodes can connect to
//  it. Note that gossip endpoints are completely distinct from Zyre node   
//  endpoints, and should not overlap (they can use the same transport).    
void QmlZyre::gossipBind (const QString &format) {
    zyre_gossip_bind (self, "%s", format.toUtf8().data());
};

///
//  Set-up gossip discovery of other nodes. A node may connect to multiple
//  other nodes, for redundancy paths. For details of the gossip network  
//  design, see the CZMQ zgossip class.                                   
void QmlZyre::gossipConnect (const QString &format) {
    zyre_gossip_connect (self, "%s", format.toUtf8().data());
};

///
//  Start node, after setting header values. When you start a node it
//  begins discovery and connection. Returns 0 if OK, -1 if it wasn't
//  possible to start the node.                                      
int QmlZyre::start () {
    return zyre_start (self);
};

///
//  Stop node; this signals to other peers that this node will go away.
//  This is polite; however you can also just destroy the node without 
//  stopping it.                                                       
void QmlZyre::stop () {
    zyre_stop (self);
};

///
//  Join a named group; after joining a group you can send messages to
//  the group and all Zyre nodes in that group will receive them.     
int QmlZyre::join (const QString &group) {
    return zyre_join (self, group.toUtf8().data());
};

///
//  Leave a group
int QmlZyre::leave (const QString &group) {
    return zyre_leave (self, group.toUtf8().data());
};

///
//  Receive next message from network; the message may be a control
//  message (ENTER, EXIT, JOIN, LEAVE) or data (WHISPER, SHOUT).   
//  Returns zmsg_t object, or NULL if interrupted                  
zmsg_t *QmlZyre::recv () {
    return zyre_recv (self);
};

///
//  Send message to single peer, specified as a UUID string
//  Destroys message after sending                         
int QmlZyre::whisper (const QString &peer, zmsg_t **msgP) {
    return zyre_whisper (self, peer.toUtf8().data(), msgP);
};

///
//  Send message to a named group 
//  Destroys message after sending
int QmlZyre::shout (const QString &group, zmsg_t **msgP) {
    return zyre_shout (self, group.toUtf8().data(), msgP);
};

///
//  Send formatted string to a single peer specified as UUID string
int QmlZyre::whispers (const QString &peer, const QString &format) {
    return zyre_whispers (self, peer.toUtf8().data(), "%s", format.toUtf8().data());
};

///
//  Send formatted string to a named group
int QmlZyre::shouts (const QString &group, const QString &format) {
    return zyre_shouts (self, group.toUtf8().data(), "%s", format.toUtf8().data());
};

///
//  Return zlist of current peer ids. The caller owns this list and should
//  destroy it when finished with it.                                     
zlist_t *QmlZyre::peers () {
    return zyre_peers (self);
};

///
//  Return zlist of currently joined groups. The caller owns this list and
//  should destroy it when finished with it.                              
zlist_t *QmlZyre::ownGroups () {
    return zyre_own_groups (self);
};

///
//  Return zlist of groups known through connected peers. The caller owns this
//  list and should destroy it when finished with it.                         
zlist_t *QmlZyre::peerGroups () {
    return zyre_peer_groups (self);
};

///
//  Return the endpoint of a connected peer. Caller owns the string.
QString QmlZyre::peerAddress (const QString &peer) {
    char *retStr_ = zyre_peer_address (self, peer.toUtf8().data());
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Return the value of a header of a conected peer. 
//  Returns null if peer or key doesn't exits. Caller
//  owns the string                                  
QString QmlZyre::peerHeaderValue (const QString &peer, const QString &name) {
    char *retStr_ = zyre_peer_header_value (self, peer.toUtf8().data(), name.toUtf8().data());
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Return socket for talking to the Zyre node, for polling
zsock_t *QmlZyre::socket () {
    return zyre_socket (self);
};


QObject* QmlZyre::qmlAttachedProperties(QObject* object) {
    return new QmlZyreAttached(object);
}


///
//  Return the Zyre version for run-time API detection
void QmlZyreAttached::version (int *major, int *minor, int *patch) {
    zyre_version (major, minor, patch);
};

///
//  Self test of this class
void QmlZyreAttached::test (bool verbose) {
    zyre_test (verbose);
};

///
//  Constructor, creates a new Zyre node. Note that until you start the
//  node it is silent and invisible to other nodes on the network.     
//  The node name is provided to other nodes during discovery. If you  
//  specify NULL, Zyre generates a randomized node name from the UUID. 
QmlZyre *QmlZyreAttached::construct (const QString &name) {
    QmlZyre *qmlSelf = new QmlZyre ();
    qmlSelf->self = zyre_new (name.toUtf8().data());
    return qmlSelf;
};

///
//  Destructor, destroys a Zyre node. When you destroy a node, any
//  messages it is sending or receiving will be discarded.        
void QmlZyreAttached::destruct (QmlZyre *qmlSelf) {
    zyre_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
