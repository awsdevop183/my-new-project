//
// MQTTClientFactory.h
//
// $Id$
//
// Library: IoT/MQTT
// Package: MQTTClient
// Module:  MQTTClientFactory
//
// Copyright (c) Continental AG and subsidiaries 2019
// All rights reserved.
//

#ifndef IoT_MQTT_MQTTClientFactory_INCLUDED
#define IoT_MQTT_MQTTClientFactory_INCLUDED

#include "IoT/MQTT/MQTTClient.h"

namespace IoT {
namespace MQTT {

class IoTMQTT_API MQTTClientFactory
{
public:
	struct ConnectOptions
	{
		int keepAliveInterval;
			/// Keep-alive interval in seconds.

		int retryInterval;
			/// Retry interval in seconds.

		int connectTimeout;
			/// Connect timeout in seconds.

		bool cleanSession;
			/// Start with a clean session.

		bool reliable;
			/// If set to true, only one message at a time can be "in flight".

		std::string username;
			/// Username for MQTT v3.1.

		std::string password;
			/// Password for MQTT v3.1.

		std::string willTopic;
			/// Last will topic name.

		std::string willMessage;
			/// Last will message.

		bool willRetained;
			/// Retained flag for will message.

		int willQoS;
			/// Quality of Service level for will message (0-2).

		int mqttVersion;
			/// Sets the version of MQTT to be used on the connect. Valid values are
			/// 0, 3 and 4.
			///   * 0 = default: start with 3.1.1, and if that fails, fall back to 3.1
			///   * 3 = only try version 3.1
			///   * 4 = only try version 3.1.1
	};
public:
	static MQTTClient::Ptr CreateClient(const std::string& serverURI, const std::string& clientId, const ConnectOptions& connectOptions);
		/// Creates a MQTTClient instance with the given server URI, client ID and connect options.
		///
		/// In case the client can not be created, it will return a NULL pointer

private:
		MQTTClientFactory();
		/// Class constructor

		~MQTTClientFactory();
		/// Class destructor
};

}} // namespace IoT::MQTT

#endif // IoT_MQTT_MQTTClientFactory_INCLUDED