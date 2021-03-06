#ifndef __MAILCORE_MCSMTPSESSION_H

#define __MAILCORE_MCSMTPSESSION_H

#include <MailCore/MCBaseTypes.h>
#include <MailCore/MCMessageConstants.h>

#ifdef __cplusplus

namespace mailcore {
	
	class Address;
	class SMTPProgressCallback;
	class MessageBuilder;

	class SMTPSession : public Object {
	public:
		SMTPSession();
		virtual ~SMTPSession();
		
		virtual void setHostname(String * hostname);
		virtual String * hostname();

		virtual void setPort(unsigned int port);
		virtual unsigned int port();

		virtual void setUsername(String * username);
		virtual String * username();

		virtual void setPassword(String * password);
		virtual String * password();

		virtual void setAuthType(AuthType authType);
		virtual AuthType authType();

		virtual void setConnectionType(ConnectionType connectionType);
		virtual ConnectionType connectionType();

		virtual void setTimeout(time_t timeout);
		virtual time_t timeout();
		
		virtual void setCheckCertificateEnabled(bool enabled);
		virtual bool isCheckCertificateEnabled();
		
		virtual void setUseHeloIPEnabled(bool enabled);
		virtual bool useHeloIPEnabled();
		
		virtual void connect(ErrorCode * pError);
		virtual void disconnect();
		
		virtual void login(ErrorCode * pError);
		
        virtual void checkAccount(Address * from, ErrorCode * pError);
        
		virtual void sendMessage(Data * messageData, SMTPProgressCallback * callback, ErrorCode * pError);
        
	private:
		String * mHostname;
		unsigned int mPort;
		String * mUsername;
		String * mPassword;
		AuthType mAuthType;
		ConnectionType mConnectionType;
		time_t mTimeout;
		bool mCheckCertificateEnabled;
		bool mUseHeloIPEnabled;
		
		mailsmtp * mSmtp;
		SMTPProgressCallback * mProgressCallback;
		int mState;
		String * mLastSMTPResponse;
        int mLastLibetpanError;
        int mLastSMTPResponseCode;
		
		void init();
		Data * dataWithFilteredBcc(Data * data);
		static void body_progress(size_t current, size_t maximum, void * context);
		void bodyProgress(unsigned int current, unsigned int maximum);
		void setup();
		void unsetup();
		void connectIfNeeded(ErrorCode * pError);
		void loginIfNeeded(ErrorCode * pError);
		bool checkCertificate();
		
		void sendMessage(Address * from, Array * recipients, Data * messageData,
                         SMTPProgressCallback * callback, ErrorCode * pError);
		void sendMessage(MessageBuilder * msg, SMTPProgressCallback * callback, ErrorCode * pError);
	};
	
}

#endif

#endif
