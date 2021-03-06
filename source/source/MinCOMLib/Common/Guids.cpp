#include "Common/Common.h"

namespace MinCOM
{

	// Core
	//////////////////////////////////////////////////////////////////////////

	// {3d24c25d-2c73-4a47-9264-a5d5b1bfdf75} 
    template<> const Guid TypeInfo< ICommon >::iid_ = 
        { 0x3d24c25d, 0x2c73, 0x4a47, { 0x92, 0x64, 0xa5, 0xd5, 0xb1, 0xbf, 0xdf, 0x75 } };
	   
	// Events
	//////////////////////////////////////////////////////////////////////////

	// {f2df16f9-16ca-41e8-b73b-6643b5700144} 
    template<> const Guid TypeInfo< IAccessPoint >::iid_ =  
        { 0xf2df16f9, 0x16ca, 0x41e8, { 0xb7, 0x3b, 0x66, 0x43, 0xb5, 0x70, 0x01, 0x44 } };

	// {b3bbe3e0-d18d-4949-b9ce-7610a75babab} 
    template<> const Guid TypeInfo< IAccessProvider >::iid_ =  
        { 0xb3bbe3e0, 0xd18d, 0x4949, { 0xb9, 0xce, 0x76, 0x10, 0xa7, 0x5b, 0xab, 0xab } };

	// Concurrency
	//////////////////////////////////////////////////////////////////////////

	// {c76d8df5-1dab-4375-b1f2-f532b4300185} 
    template<> const Guid TypeInfo< IThread >::iid_ =  
        { 0xc76d8df5, 0x1dab, 0x4375, { 0xb1, 0xf2, 0xf5, 0x32, 0xb4, 0x30, 0x01, 0x85 } };

	// {e137a6ce-1daa-4e7f-b157-eb9be83d3256} 
    template<> const Guid TypeInfo< IEvent >::iid_ = 
        { 0xe137a6ce, 0x1daa, 0x4e7f, { 0xb1, 0x57, 0xeb, 0x9b, 0xe8, 0x3d, 0x32, 0x56 } };

	// {2d5835d5-54f9-4063-a2b6-935b16d631b2} 
    template<> const Guid TypeInfo< ISynchro >::iid_ = 
        { 0x2d5835d5, 0x54f9, 0x4063, { 0xa2, 0xb6, 0x93, 0x5b, 0x16, 0xd6, 0x31, 0xb2 } };

	// {e615e39d-191f-4ab1-8c2d-2385a05d79e3} 
    template<> const Guid TypeInfo< IMutex >::iid_ = 
        { 0xe615e39d, 0x191f, 0x4ab1, { 0x8c, 0x2d, 0x23, 0x85, 0xa0, 0x5d, 0x79, 0xe3 } };

	// {6E8FF0F1-C592-405f-B646-B0681ADB6392}
    template<> const Guid TypeInfo< IRunnable >::iid_ = 
        { 0x6e8ff0f1, 0xc592, 0x405f, { 0xb6, 0x46, 0xb0, 0x68, 0x1a, 0xdb, 0x63, 0x92 } };
    
	// {6fc2e099-3f36-4675-8233-1d45180309cf} 
    template<> const Guid TypeInfo< IJobsQueue >::iid_ = 
        { 0x6fc2e099, 0x3f36, 0x4675, { 0x82, 0x33, 0x1d, 0x45, 0x18, 0x03, 0x09, 0xcf } };
    
	// {df043049-1d54-4a3e-99fd-8184561cf9da} 
    template<> const Guid TypeInfo< ISemaphore >::iid_ = 
        { 0xdf043049, 0x1d54, 0x4a3e, { 0x99, 0xfd, 0x81, 0x84, 0x56, 0x1c, 0xf9, 0xda } };

	// {764F2FCD-EDE7-4ae9-A03F-608FC0D94664}
	template<> const Guid TypeInfo< IReadWriteLock >::iid_ = 
        { 0x764f2fcd, 0xede7, 0x4ae9, { 0xa0, 0x3f, 0x60, 0x8f, 0xc0, 0xd9, 0x46, 0x64 } };
    
	// Commands
	//////////////////////////////////////////////////////////////////////////

	// {f214fdf2-311b-41ea-b15e-c8f659ce3814} 
    template<> const Guid TypeInfo< ICommand >::iid_ = 
        { 0xf214fdf2, 0x311b, 0x41ea, { 0xb1, 0x5e, 0xc8, 0xf6, 0x59, 0xce, 0x38, 0x14 } };

	// {6c047399-208b-48ca-9b48-cabd6bf999af} 
    template<> const Guid TypeInfo< ICommands >::iid_ = 
        { 0x6c047399, 0x208b, 0x48ca, { 0x9b, 0x48, 0xca, 0xbd, 0x6b, 0xf9, 0x99, 0xaf } };

	// {FB75E71B-E1B0-41ab-8F66-FDAD4CF6FFEE}
    template<> const Guid TypeInfo< DCommands >::iid_ = 
        { 0xfb75e71b, 0xe1b0, 0x41ab, { 0x8f, 0x66, 0xfd, 0xad, 0x4c, 0xf6, 0xff, 0xee } };

	// Factory
	//////////////////////////////////////////////////////////////////////////

	// {210dd592-1d09-475e-9c4a-9f14ed0147fd} 
    template<> const Guid TypeInfo< IFactory >::iid_ = 
        { 0x210dd592, 0x1d09, 0x475e, { 0x9c, 0x4a, 0x9f, 0x14, 0xed, 0x01, 0x47, 0xfd } };

	// Variant
	//////////////////////////////////////////////////////////////////////////

	// {DABD6BC6-F7A6-4a97-8AC5-26A2D7A9EA26}
    template<> const Guid TypeInfo< IWrapperT< std::string > >::iid_ = 
        { 0xdabd6bc6, 0xf7a6, 0x4a97, { 0x8a, 0xc5, 0x26, 0xa2, 0xd7, 0xa9, 0xea, 0x26 } };

	// {B8CE0E70-0EBF-4f7c-9FB1-B56987139145}
    template<> const Guid TypeInfo< IWrapperT< std::wstring > >::iid_ =  
        { 0xb8ce0e70, 0xebf, 0x4f7c, { 0x9f, 0xb1, 0xb5, 0x69, 0x87, 0x13, 0x91, 0x45 } };

	// Network
	//////////////////////////////////////////////////////////////////////////

	// {a59cd1a9-28ce-46f3-8cb5-ce28d5f2bedc} 
    template<> const Guid TypeInfo< IHost >::iid_ =  
        { 0xa59cd1a9, 0x28ce, 0x46f3, { 0x8c, 0xb5, 0xce, 0x28, 0xd5, 0xf2, 0xbe, 0xdc } };

	// {871a153d-b6d2-4851-8275-81c1ae41a4dd} 
    template<> const Guid TypeInfo< IServer >::iid_ =  
        { 0x871a153d, 0xb6d2, 0x4851, { 0x82, 0x75, 0x81, 0xc1, 0xae, 0x41, 0xa4, 0xdd } };

	// {2464e7c4-fac7-43bb-a104-75b1baeb833d} 
    template<> const Guid TypeInfo< IConnection >::iid_ =  
        { 0x2464e7c4, 0xfac7, 0x43bb, { 0xa1, 0x04, 0x75, 0xb1, 0xba, 0xeb, 0x83, 0x3d } };

	// {1C9BE63F-2AC2-478d-BC19-F2AF545DABC1}
    template<> const Guid TypeInfo< DRawData >::iid_ = 
        { 0x1c9be63f, 0x2ac2, 0x478d, { 0xbc, 0x19, 0xf2, 0xaf, 0x54, 0x5d, 0xab, 0xc1 } };

	// {D8C1629C-4991-4442-B3DA-A39827F30089}
	template<> const Guid TypeInfo< DServer >::iid_ = 
        { 0xd8c1629c, 0x4991, 0x4442, { 0xb3, 0xda, 0xa3, 0x98, 0x27, 0xf3, 0x0, 0x89 } };

	// {AC1A8C86-400A-41cb-83AB-0507C7A8448C}
    template<> const Guid TypeInfo< IService >::iid_ = 
        { 0xac1a8c86, 0x400a, 0x41cb, { 0x83, 0xab, 0x5, 0x7, 0xc7, 0xa8, 0x44, 0x8c } };

	// {182b74d5-ecac-4285-9c83-86569fdcac80} 
    template<> const Guid TypeInfo< IMessage >::iid_ = 
        { 0x182b74d5, 0xecac, 0x4285, { 0x9c, 0x83, 0x86, 0x56, 0x9f, 0xdc, 0xac, 0x80 } };

	// {fd3fec5e-51b4-4dd3-913e-1b59de3d0fb4} 
    template<> const Guid TypeInfo< IProtocol >::iid_ = 
        { 0xfd3fec5e, 0x51b4, 0x4dd3, { 0x91, 0x3e, 0x1b, 0x59, 0xde, 0x3d, 0x0f, 0xb4 } };

	// {9481DCC0-DD41-4b48-A070-EEE404DD181A}
	template<> const Guid TypeInfo< DProtocol >::iid_ = 
        { 0x9481dcc0, 0xdd41, 0x4b48, { 0xa0, 0x70, 0xee, 0xe4, 0x4, 0xdd, 0x18, 0x1a } };
	
	// {A9037958-6F12-424D-B4A6-EE9AA150BB7E}
	template<> const Guid TypeInfo< INetworkStats >::iid_ = 	
        { 0xA9037958, 0x6F12, 0x424D, { 0xB4, 0xA6, 0xEE, 0x9A, 0xA1, 0x50, 0xBB, 0x7E } };

	// Containers
	//////////////////////////////////////////////////////////////////////////

	// {04598E44-BB10-4708-9F0E-80C0A6ADE652}
    template<> const Guid TypeInfo< IVector >::iid_ = 
        { 0x4598e44, 0xbb10, 0x4708, { 0x9f, 0xe, 0x80, 0xc0, 0xa6, 0xad, 0xe6, 0x52 } };

	// {6C9E5241-1636-466b-AD4E-5E59C89FFCDE}    
    template<> const Guid TypeInfo< IList >::iid_ = 
        { 0x6c9e5241, 0x1636, 0x466b, { 0xad, 0x4e, 0x5e, 0x59, 0xc8, 0x9f, 0xfc, 0xde } };

	// {160F53D1-CE66-4553-9F24-6B2625C0489E}
    template<> const Guid TypeInfo< IIterator >::iid_ = 
        { 0x160f53d1, 0xce66, 0x4553, { 0x9f, 0x24, 0x6b, 0x26, 0x25, 0xc0, 0x48, 0x9e } };

	// {D729F07B-34F2-484d-A896-86A407A7DECE}
    template<> const Guid TypeInfo< DContainer >::iid_ = 
        { 0xd729f07b, 0x34f2, 0x484d, { 0xa8, 0x96, 0x86, 0xa4, 0x7, 0xa7, 0xde, 0xce } };

	// {C94DBBCE-BF35-45e9-B346-C35FF3E36680}
	template<> const Guid TypeInfo< IEnumerator >::iid_ = 
        { 0xc94dbbce, 0xbf35, 0x45e9, { 0xb3, 0x46, 0xc3, 0x5f, 0xf3, 0xe3, 0x66, 0x80 } };

}
