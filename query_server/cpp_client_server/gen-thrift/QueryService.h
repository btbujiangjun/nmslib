/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef QueryService_H
#define QueryService_H

#include <thrift/TDispatchProcessor.h>
#include "protocol_types.h"

namespace similarity {

class QueryServiceIf {
 public:
  virtual ~QueryServiceIf() {}
  virtual void setQueryTimeParams(const std::string& queryTimeParams) = 0;
  virtual void knnQuery(ReplyEntryList& _return, const int32_t k, const std::string& queryObj, const bool retExternId, const bool retObj) = 0;
  virtual void rangeQuery(ReplyEntryList& _return, const double r, const std::string& queryObj, const bool retExternId, const bool retObj) = 0;
  virtual double getDistance(const std::string& obj1, const std::string& obj2) = 0;
};

class QueryServiceIfFactory {
 public:
  typedef QueryServiceIf Handler;

  virtual ~QueryServiceIfFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(QueryServiceIf* /* handler */) = 0;
};

class QueryServiceIfSingletonFactory : virtual public QueryServiceIfFactory {
 public:
  QueryServiceIfSingletonFactory(const boost::shared_ptr<QueryServiceIf>& iface) : iface_(iface) {}
  virtual ~QueryServiceIfSingletonFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(QueryServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<QueryServiceIf> iface_;
};

class QueryServiceNull : virtual public QueryServiceIf {
 public:
  virtual ~QueryServiceNull() {}
  void setQueryTimeParams(const std::string& /* queryTimeParams */) {
    return;
  }
  void knnQuery(ReplyEntryList& /* _return */, const int32_t /* k */, const std::string& /* queryObj */, const bool /* retExternId */, const bool /* retObj */) {
    return;
  }
  void rangeQuery(ReplyEntryList& /* _return */, const double /* r */, const std::string& /* queryObj */, const bool /* retExternId */, const bool /* retObj */) {
    return;
  }
  double getDistance(const std::string& /* obj1 */, const std::string& /* obj2 */) {
    double _return = (double)0;
    return _return;
  }
};


class QueryService_setQueryTimeParams_args {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  QueryService_setQueryTimeParams_args(const QueryService_setQueryTimeParams_args&);
  QueryService_setQueryTimeParams_args& operator=(const QueryService_setQueryTimeParams_args&);
  QueryService_setQueryTimeParams_args() : queryTimeParams() {
  }

  virtual ~QueryService_setQueryTimeParams_args() throw();
  std::string queryTimeParams;

  void __set_queryTimeParams(const std::string& val);

  bool operator == (const QueryService_setQueryTimeParams_args & rhs) const
  {
    if (!(queryTimeParams == rhs.queryTimeParams))
      return false;
    return true;
  }
  bool operator != (const QueryService_setQueryTimeParams_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_setQueryTimeParams_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_setQueryTimeParams_args& obj);
};


class QueryService_setQueryTimeParams_pargs {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};


  virtual ~QueryService_setQueryTimeParams_pargs() throw();
  const std::string* queryTimeParams;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_setQueryTimeParams_pargs& obj);
};

typedef struct _QueryService_setQueryTimeParams_result__isset {
  _QueryService_setQueryTimeParams_result__isset() : err(false) {}
  bool err :1;
} _QueryService_setQueryTimeParams_result__isset;

class QueryService_setQueryTimeParams_result {
 public:

  static const char* ascii_fingerprint; // = "771E7EF40B572D2BFAB12C49547ADCBF";
  static const uint8_t binary_fingerprint[16]; // = {0x77,0x1E,0x7E,0xF4,0x0B,0x57,0x2D,0x2B,0xFA,0xB1,0x2C,0x49,0x54,0x7A,0xDC,0xBF};

  QueryService_setQueryTimeParams_result(const QueryService_setQueryTimeParams_result&);
  QueryService_setQueryTimeParams_result& operator=(const QueryService_setQueryTimeParams_result&);
  QueryService_setQueryTimeParams_result() {
  }

  virtual ~QueryService_setQueryTimeParams_result() throw();
  QueryException err;

  _QueryService_setQueryTimeParams_result__isset __isset;

  void __set_err(const QueryException& val);

  bool operator == (const QueryService_setQueryTimeParams_result & rhs) const
  {
    if (!(err == rhs.err))
      return false;
    return true;
  }
  bool operator != (const QueryService_setQueryTimeParams_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_setQueryTimeParams_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_setQueryTimeParams_result& obj);
};

typedef struct _QueryService_setQueryTimeParams_presult__isset {
  _QueryService_setQueryTimeParams_presult__isset() : err(false) {}
  bool err :1;
} _QueryService_setQueryTimeParams_presult__isset;

class QueryService_setQueryTimeParams_presult {
 public:

  static const char* ascii_fingerprint; // = "771E7EF40B572D2BFAB12C49547ADCBF";
  static const uint8_t binary_fingerprint[16]; // = {0x77,0x1E,0x7E,0xF4,0x0B,0x57,0x2D,0x2B,0xFA,0xB1,0x2C,0x49,0x54,0x7A,0xDC,0xBF};


  virtual ~QueryService_setQueryTimeParams_presult() throw();
  QueryException err;

  _QueryService_setQueryTimeParams_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const QueryService_setQueryTimeParams_presult& obj);
};


class QueryService_knnQuery_args {
 public:

  static const char* ascii_fingerprint; // = "67C8FAD6AD85FAD6B99875970D1F771E";
  static const uint8_t binary_fingerprint[16]; // = {0x67,0xC8,0xFA,0xD6,0xAD,0x85,0xFA,0xD6,0xB9,0x98,0x75,0x97,0x0D,0x1F,0x77,0x1E};

  QueryService_knnQuery_args(const QueryService_knnQuery_args&);
  QueryService_knnQuery_args& operator=(const QueryService_knnQuery_args&);
  QueryService_knnQuery_args() : k(0), queryObj(), retExternId(0), retObj(0) {
  }

  virtual ~QueryService_knnQuery_args() throw();
  int32_t k;
  std::string queryObj;
  bool retExternId;
  bool retObj;

  void __set_k(const int32_t val);

  void __set_queryObj(const std::string& val);

  void __set_retExternId(const bool val);

  void __set_retObj(const bool val);

  bool operator == (const QueryService_knnQuery_args & rhs) const
  {
    if (!(k == rhs.k))
      return false;
    if (!(queryObj == rhs.queryObj))
      return false;
    if (!(retExternId == rhs.retExternId))
      return false;
    if (!(retObj == rhs.retObj))
      return false;
    return true;
  }
  bool operator != (const QueryService_knnQuery_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_knnQuery_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_knnQuery_args& obj);
};


class QueryService_knnQuery_pargs {
 public:

  static const char* ascii_fingerprint; // = "67C8FAD6AD85FAD6B99875970D1F771E";
  static const uint8_t binary_fingerprint[16]; // = {0x67,0xC8,0xFA,0xD6,0xAD,0x85,0xFA,0xD6,0xB9,0x98,0x75,0x97,0x0D,0x1F,0x77,0x1E};


  virtual ~QueryService_knnQuery_pargs() throw();
  const int32_t* k;
  const std::string* queryObj;
  const bool* retExternId;
  const bool* retObj;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_knnQuery_pargs& obj);
};

typedef struct _QueryService_knnQuery_result__isset {
  _QueryService_knnQuery_result__isset() : success(false), err(false) {}
  bool success :1;
  bool err :1;
} _QueryService_knnQuery_result__isset;

class QueryService_knnQuery_result {
 public:

  static const char* ascii_fingerprint; // = "0FB934CFA1E6389C2C7454E26D9D32BF";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0xB9,0x34,0xCF,0xA1,0xE6,0x38,0x9C,0x2C,0x74,0x54,0xE2,0x6D,0x9D,0x32,0xBF};

  QueryService_knnQuery_result(const QueryService_knnQuery_result&);
  QueryService_knnQuery_result& operator=(const QueryService_knnQuery_result&);
  QueryService_knnQuery_result() {
  }

  virtual ~QueryService_knnQuery_result() throw();
  ReplyEntryList success;
  QueryException err;

  _QueryService_knnQuery_result__isset __isset;

  void __set_success(const ReplyEntryList& val);

  void __set_err(const QueryException& val);

  bool operator == (const QueryService_knnQuery_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(err == rhs.err))
      return false;
    return true;
  }
  bool operator != (const QueryService_knnQuery_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_knnQuery_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_knnQuery_result& obj);
};

typedef struct _QueryService_knnQuery_presult__isset {
  _QueryService_knnQuery_presult__isset() : success(false), err(false) {}
  bool success :1;
  bool err :1;
} _QueryService_knnQuery_presult__isset;

class QueryService_knnQuery_presult {
 public:

  static const char* ascii_fingerprint; // = "0FB934CFA1E6389C2C7454E26D9D32BF";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0xB9,0x34,0xCF,0xA1,0xE6,0x38,0x9C,0x2C,0x74,0x54,0xE2,0x6D,0x9D,0x32,0xBF};


  virtual ~QueryService_knnQuery_presult() throw();
  ReplyEntryList* success;
  QueryException err;

  _QueryService_knnQuery_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const QueryService_knnQuery_presult& obj);
};


class QueryService_rangeQuery_args {
 public:

  static const char* ascii_fingerprint; // = "60E12AF76B11F08F5E27C7C34596DCDA";
  static const uint8_t binary_fingerprint[16]; // = {0x60,0xE1,0x2A,0xF7,0x6B,0x11,0xF0,0x8F,0x5E,0x27,0xC7,0xC3,0x45,0x96,0xDC,0xDA};

  QueryService_rangeQuery_args(const QueryService_rangeQuery_args&);
  QueryService_rangeQuery_args& operator=(const QueryService_rangeQuery_args&);
  QueryService_rangeQuery_args() : r(0), queryObj(), retExternId(0), retObj(0) {
  }

  virtual ~QueryService_rangeQuery_args() throw();
  double r;
  std::string queryObj;
  bool retExternId;
  bool retObj;

  void __set_r(const double val);

  void __set_queryObj(const std::string& val);

  void __set_retExternId(const bool val);

  void __set_retObj(const bool val);

  bool operator == (const QueryService_rangeQuery_args & rhs) const
  {
    if (!(r == rhs.r))
      return false;
    if (!(queryObj == rhs.queryObj))
      return false;
    if (!(retExternId == rhs.retExternId))
      return false;
    if (!(retObj == rhs.retObj))
      return false;
    return true;
  }
  bool operator != (const QueryService_rangeQuery_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_rangeQuery_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_rangeQuery_args& obj);
};


class QueryService_rangeQuery_pargs {
 public:

  static const char* ascii_fingerprint; // = "60E12AF76B11F08F5E27C7C34596DCDA";
  static const uint8_t binary_fingerprint[16]; // = {0x60,0xE1,0x2A,0xF7,0x6B,0x11,0xF0,0x8F,0x5E,0x27,0xC7,0xC3,0x45,0x96,0xDC,0xDA};


  virtual ~QueryService_rangeQuery_pargs() throw();
  const double* r;
  const std::string* queryObj;
  const bool* retExternId;
  const bool* retObj;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_rangeQuery_pargs& obj);
};

typedef struct _QueryService_rangeQuery_result__isset {
  _QueryService_rangeQuery_result__isset() : success(false), err(false) {}
  bool success :1;
  bool err :1;
} _QueryService_rangeQuery_result__isset;

class QueryService_rangeQuery_result {
 public:

  static const char* ascii_fingerprint; // = "0FB934CFA1E6389C2C7454E26D9D32BF";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0xB9,0x34,0xCF,0xA1,0xE6,0x38,0x9C,0x2C,0x74,0x54,0xE2,0x6D,0x9D,0x32,0xBF};

  QueryService_rangeQuery_result(const QueryService_rangeQuery_result&);
  QueryService_rangeQuery_result& operator=(const QueryService_rangeQuery_result&);
  QueryService_rangeQuery_result() {
  }

  virtual ~QueryService_rangeQuery_result() throw();
  ReplyEntryList success;
  QueryException err;

  _QueryService_rangeQuery_result__isset __isset;

  void __set_success(const ReplyEntryList& val);

  void __set_err(const QueryException& val);

  bool operator == (const QueryService_rangeQuery_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(err == rhs.err))
      return false;
    return true;
  }
  bool operator != (const QueryService_rangeQuery_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_rangeQuery_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_rangeQuery_result& obj);
};

typedef struct _QueryService_rangeQuery_presult__isset {
  _QueryService_rangeQuery_presult__isset() : success(false), err(false) {}
  bool success :1;
  bool err :1;
} _QueryService_rangeQuery_presult__isset;

class QueryService_rangeQuery_presult {
 public:

  static const char* ascii_fingerprint; // = "0FB934CFA1E6389C2C7454E26D9D32BF";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0xB9,0x34,0xCF,0xA1,0xE6,0x38,0x9C,0x2C,0x74,0x54,0xE2,0x6D,0x9D,0x32,0xBF};


  virtual ~QueryService_rangeQuery_presult() throw();
  ReplyEntryList* success;
  QueryException err;

  _QueryService_rangeQuery_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const QueryService_rangeQuery_presult& obj);
};


class QueryService_getDistance_args {
 public:

  static const char* ascii_fingerprint; // = "07A9615F837F7D0A952B595DD3020972";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0xA9,0x61,0x5F,0x83,0x7F,0x7D,0x0A,0x95,0x2B,0x59,0x5D,0xD3,0x02,0x09,0x72};

  QueryService_getDistance_args(const QueryService_getDistance_args&);
  QueryService_getDistance_args& operator=(const QueryService_getDistance_args&);
  QueryService_getDistance_args() : obj1(), obj2() {
  }

  virtual ~QueryService_getDistance_args() throw();
  std::string obj1;
  std::string obj2;

  void __set_obj1(const std::string& val);

  void __set_obj2(const std::string& val);

  bool operator == (const QueryService_getDistance_args & rhs) const
  {
    if (!(obj1 == rhs.obj1))
      return false;
    if (!(obj2 == rhs.obj2))
      return false;
    return true;
  }
  bool operator != (const QueryService_getDistance_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_getDistance_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_getDistance_args& obj);
};


class QueryService_getDistance_pargs {
 public:

  static const char* ascii_fingerprint; // = "07A9615F837F7D0A952B595DD3020972";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0xA9,0x61,0x5F,0x83,0x7F,0x7D,0x0A,0x95,0x2B,0x59,0x5D,0xD3,0x02,0x09,0x72};


  virtual ~QueryService_getDistance_pargs() throw();
  const std::string* obj1;
  const std::string* obj2;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_getDistance_pargs& obj);
};

typedef struct _QueryService_getDistance_result__isset {
  _QueryService_getDistance_result__isset() : success(false), err(false) {}
  bool success :1;
  bool err :1;
} _QueryService_getDistance_result__isset;

class QueryService_getDistance_result {
 public:

  static const char* ascii_fingerprint; // = "505FDFAFB3792C9C02EC411D1B8DBD35";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x5F,0xDF,0xAF,0xB3,0x79,0x2C,0x9C,0x02,0xEC,0x41,0x1D,0x1B,0x8D,0xBD,0x35};

  QueryService_getDistance_result(const QueryService_getDistance_result&);
  QueryService_getDistance_result& operator=(const QueryService_getDistance_result&);
  QueryService_getDistance_result() : success(0) {
  }

  virtual ~QueryService_getDistance_result() throw();
  double success;
  QueryException err;

  _QueryService_getDistance_result__isset __isset;

  void __set_success(const double val);

  void __set_err(const QueryException& val);

  bool operator == (const QueryService_getDistance_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(err == rhs.err))
      return false;
    return true;
  }
  bool operator != (const QueryService_getDistance_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_getDistance_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const QueryService_getDistance_result& obj);
};

typedef struct _QueryService_getDistance_presult__isset {
  _QueryService_getDistance_presult__isset() : success(false), err(false) {}
  bool success :1;
  bool err :1;
} _QueryService_getDistance_presult__isset;

class QueryService_getDistance_presult {
 public:

  static const char* ascii_fingerprint; // = "505FDFAFB3792C9C02EC411D1B8DBD35";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x5F,0xDF,0xAF,0xB3,0x79,0x2C,0x9C,0x02,0xEC,0x41,0x1D,0x1B,0x8D,0xBD,0x35};


  virtual ~QueryService_getDistance_presult() throw();
  double* success;
  QueryException err;

  _QueryService_getDistance_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const QueryService_getDistance_presult& obj);
};

class QueryServiceClient : virtual public QueryServiceIf {
 public:
  QueryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  QueryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void setQueryTimeParams(const std::string& queryTimeParams);
  void send_setQueryTimeParams(const std::string& queryTimeParams);
  void recv_setQueryTimeParams();
  void knnQuery(ReplyEntryList& _return, const int32_t k, const std::string& queryObj, const bool retExternId, const bool retObj);
  void send_knnQuery(const int32_t k, const std::string& queryObj, const bool retExternId, const bool retObj);
  void recv_knnQuery(ReplyEntryList& _return);
  void rangeQuery(ReplyEntryList& _return, const double r, const std::string& queryObj, const bool retExternId, const bool retObj);
  void send_rangeQuery(const double r, const std::string& queryObj, const bool retExternId, const bool retObj);
  void recv_rangeQuery(ReplyEntryList& _return);
  double getDistance(const std::string& obj1, const std::string& obj2);
  void send_getDistance(const std::string& obj1, const std::string& obj2);
  double recv_getDistance();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class QueryServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<QueryServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (QueryServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_setQueryTimeParams(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_knnQuery(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_rangeQuery(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDistance(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  QueryServiceProcessor(boost::shared_ptr<QueryServiceIf> iface) :
    iface_(iface) {
    processMap_["setQueryTimeParams"] = &QueryServiceProcessor::process_setQueryTimeParams;
    processMap_["knnQuery"] = &QueryServiceProcessor::process_knnQuery;
    processMap_["rangeQuery"] = &QueryServiceProcessor::process_rangeQuery;
    processMap_["getDistance"] = &QueryServiceProcessor::process_getDistance;
  }

  virtual ~QueryServiceProcessor() {}
};

class QueryServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  QueryServiceProcessorFactory(const ::boost::shared_ptr< QueryServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< QueryServiceIfFactory > handlerFactory_;
};

class QueryServiceMultiface : virtual public QueryServiceIf {
 public:
  QueryServiceMultiface(std::vector<boost::shared_ptr<QueryServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~QueryServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<QueryServiceIf> > ifaces_;
  QueryServiceMultiface() {}
  void add(boost::shared_ptr<QueryServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void setQueryTimeParams(const std::string& queryTimeParams) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setQueryTimeParams(queryTimeParams);
    }
    ifaces_[i]->setQueryTimeParams(queryTimeParams);
  }

  void knnQuery(ReplyEntryList& _return, const int32_t k, const std::string& queryObj, const bool retExternId, const bool retObj) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->knnQuery(_return, k, queryObj, retExternId, retObj);
    }
    ifaces_[i]->knnQuery(_return, k, queryObj, retExternId, retObj);
    return;
  }

  void rangeQuery(ReplyEntryList& _return, const double r, const std::string& queryObj, const bool retExternId, const bool retObj) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->rangeQuery(_return, r, queryObj, retExternId, retObj);
    }
    ifaces_[i]->rangeQuery(_return, r, queryObj, retExternId, retObj);
    return;
  }

  double getDistance(const std::string& obj1, const std::string& obj2) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDistance(obj1, obj2);
    }
    return ifaces_[i]->getDistance(obj1, obj2);
  }

};

} // namespace

#endif