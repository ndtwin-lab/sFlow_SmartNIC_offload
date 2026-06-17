
if [ ! /opt/netronome/p4/bin/rtecli ]; then
    echo "Error: Netronome P4 tools not found. Please install the Netronome P4 SDK."
    echo "Follow the https://github.com/guimvmatos/Agilio-P4-SmartNIC repo for installation instructions."
    exit 1
fi

if [ ! -f "sFlow-offload.nffw" ]; then
    echo "Error: sFlow-offload.nffw not found. Please build the P4 program first."
    exit 1
fi

sudo /opt/netronome/p4/bin/rtecli design-load -f sFlow-offload.nffw -p out/pif_design.json
sudo /opt/netronome/p4/bin/rtecli config-reload -c conf.p4cfg
