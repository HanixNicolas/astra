#ifndef PLUGIN_CALLBACKS_H
#define PLUGIN_CALLBACKS_H

#include <SenseKit/sensekit_capi.h>

typedef void(*set_parameter_callback_t)(void*, sensekit_streamconnection_t,
                                        sensekit_parameter_id,
                                        size_t,
                                        sensekit_parameter_data_t);

typedef void(*get_parameter_callback_t)(void*,
                                        sensekit_streamconnection_t,
                                        sensekit_parameter_id,
                                        sensekit_parameter_bin_t*);

typedef void(*invoke_callback_t)(void*,
                                 sensekit_streamconnection_t,
                                 sensekit_command_id, 
                                 size_t,
                                 sensekit_parameter_data_t,
                                 sensekit_parameter_bin_t*);

typedef void(*connection_added_callback_t)(void*, sensekit_stream_t, sensekit_streamconnection_t);
typedef void(*connection_removed_callback_t)(void*, sensekit_stream_t, sensekit_bin_t, sensekit_streamconnection_t);

typedef void(*stream_added_callback_t)(void*,
                                       sensekit_streamset_t,
                                       sensekit_stream_t,
                                       sensekit_stream_desc_t);

typedef void(*stream_removing_callback_t)(void*,
                                          sensekit_streamset_t,
                                          sensekit_stream_t,
                                          sensekit_stream_desc_t);

struct stream_callbacks_t {
    void* context;
    set_parameter_callback_t setParameterCallback;
    get_parameter_callback_t getParameterCallback;
    invoke_callback_t invokeCallback;
    connection_added_callback_t connectionAddedCallback;
    connection_removed_callback_t connectionRemovedCallback;
};

#endif /* PLUGIN_CALLBACKS_H */