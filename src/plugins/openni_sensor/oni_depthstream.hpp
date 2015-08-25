#ifndef ONI_DEPTHSTREAM_H
#define ONI_DEPTHSTREAM_H

#include "oni_devicestream.hpp"
#include <Astra/Plugins/plugin_capi.h>
#include <AstraUL/Plugins/stream_types.h>
#include <AstraUL/skul_ctypes.h>
#include <cmath>
#include <Shiny.h>

namespace orbbec { namespace ni {

    class depthstream : public devicestream<astra_imageframe_wrapper_t, int16_t>
    {
    public:
        depthstream(astra::PluginServiceProxy& pluginService,
                    astra_streamset_t streamSet,
                    openni::Device& oniDevice);

        depthstream(const depthstream&) = delete;
        depthstream& operator=(const depthstream&) = delete;

    private:
        conversion_cache_t conversionCache_;

        void refresh_conversion_cache(float horizontalFov,
                                      float verticalFov,
                                      int resolutionX,
                                      int resolutionY);

        virtual void on_open() override;

        virtual void on_get_parameter(astra_streamconnection_t connection,
                                      astra_parameter_id id,
                                      astra_parameter_bin_t& parameterBin) override;

        virtual void on_connection_removed(astra_bin_t bin,
                                           astra_streamconnection_t connection) override;
    };
}}

#endif /* ONIDEPTHSTREAM_H */
