#include "musicformats.h"

QStringList MusicFormats::supportFormatsString()
{
    return QStringList()<< "mpc"
                        << "wv"
                        << "ogg"
                        << "opus"
                        << "wav" << "au" << "snd" << "aif" << "aiff" << "8svx" << "sph" << "sf" << "voc" << "w64"
                        << "cue"
                        << "mp1" << "mp2" << "mp3"
                        << "ay" << "gms" << "gym" << "hes" << "kss" << "nsf" << "nsfe" << "sap" << "spc" << "vgm" << "vgz)"
                        << "flac" << "oga"
                        << "ape"
                        << "aac"
                        << "mid"
                        << "sid" << "mus" << "str" << "prg" << "P00"
                        << "wma" << "ape" << "tta" << "m4a" << "ra" << "shn" << "vqf" << "ac3" << "tak" << "dsf" << "dsdiff" << "webm"
                        << "mod" << "s3m" << "xm" << "it" << "669" << "amf" << "ams" << "dbm" << "dmf" << "dsm" << "far" << "mdl" << "med" << "mtm" << "okt" << "ptm" << "stm" << "ult" << "umx" << "mt2" << "psm" << "mdz" << "s3z" << "xmz" << "itz" << "mdr" << "s3r" << "xmr" << "itr" << "dgz" << "s3gz" << "xmgz" << "itgz"
                        << "adl" << "hsc" << "ksm" << "lds" << "amd" << "d00" << "rad"
                        << "sap" << "cm3" << "cmc" << "cmr" << "cms" << "dmc" << "dlt" << "mpd" << "mpt" << "rmt" << "tm2" << "tm8" << "tmc"
                        << "vtx" << "asc" << "sqt" << "psg" << "stc" << "stp" << "pt1" << "pt2" << "pt3" << "psc" << "ay"
                        << "dts" << "cpt"
                        << "fc" << "fc13" << "fc14" << "smod"
                        << "ahx" << "hvl"
                        << "ofr" << "ofs"
                        << "psf" << "spu" << "ssf" << "qsf" << "dsf" << "minipsf" << "minissf" << "miniqsf" << "minidsf"
                        << "sc68"
                        << "spx"
                        << "v2m"
                        << "ym"
                        << "zip";
}

TTKStringListMap MusicFormats::supportFormatsStringMap()
{
    TTKStringListMap formats;
    formats.insert("mpc", QStringList() << "mpc");
    formats.insert("wavpack", QStringList() << "wv");
    formats.insert("vorbis", QStringList() << "ogg");
    formats.insert("opus", QStringList() << "opus");
    formats.insert("sndfile", QStringList() << "wav" << "au" << "snd" << "aif" << "aiff" << "8svx" << "sph" << "sf" << "voc" << "w64");
    formats.insert("cue", QStringList() << "cue");
    formats.insert("mpeg", QStringList() << "mp1" << "mp2" << "mp3");
    formats.insert("gme", QStringList() << "ay" << "gms" << "gym" << "hes" << "kss" << "nsf" << "nsfe" << "sap" << "spc" << "vgm" << "vgz)");
    formats.insert("flac", QStringList() << "flac" << "oga");
    formats.insert("ffap", QStringList() << "ape");
    formats.insert("aac", QStringList() << "aac");
    formats.insert("wildmidi", QStringList() << "mid");
    formats.insert("sid", QStringList() << "sid" << "mus" << "str" << "prg" << "P00");
    formats.insert("ffmpeg", QStringList() << "wma" << "ape" << "tta" << "m4a" << "ra" << "shn" << "vqf" << "ac3" << "tak" << "dsf" << "dsdiff" << "webm");
    formats.insert("modplug", QStringList() << "mod" << "s3m" << "xm" << "it" << "669" << "amf" << "ams" << "dbm" << "dmf" << "dsm" << "far" << "mdl" << "med" << "mtm" << "okt" << "ptm" << "stm" << "ult" << "umx" << "mt2" << "psm" << "mdz" << "s3z" << "xmz" << "itz" << "mdr" << "s3r" << "xmr" << "itr" << "dgz" << "s3gz" << "xmgz" << "itgz");
    formats.insert("adplug", QStringList() << "adl" << "hsc" << "ksm" << "lds" << "amd" << "d00" << "rad");
    formats.insert("asap", QStringList() << "sap" << "cm3" << "cmc" << "cmr" << "cms" << "dmc" << "dlt" << "mpd" << "mpt" << "rmt" << "tm2" << "tm8" << "tmc" << "fc");
    formats.insert("ayfly", QStringList() << "vtx" << "asc" << "sqt" << "psg" << "stc" << "stp" << "pt1" << "pt2" << "pt3" << "psc" << "ay");
    formats.insert("dca", QStringList() << "dts" << "cpt");
    formats.insert("fc14", QStringList() << "fc" << "fc13" << "fc14" << "smod");
    formats.insert("hively", QStringList() << "ahx" << "hvl");
    formats.insert("optimfrog", QStringList() << "ofr" << "ofs");
    formats.insert("psf", QStringList() << "psf" << "spu" << "ssf" << "qsf" << "dsf" << "minipsf" << "minissf" << "miniqsf" << "minidsf");
    formats.insert("sc68", QStringList() << "sc68");
    formats.insert("speex", QStringList() << "spx");
    formats.insert("v2m", QStringList() << "v2m");
    formats.insert("ym", QStringList() << "ym");
    formats.insert("zip", QStringList() << "zip");
    return formats;
}

QStringList MusicFormats::supportFormatsFilterString()
{
    return QStringList()<< "*.mpc"
                        << "*.wv"
                        << "*.ogg"
                        << "*.opus"
                        << "*.wav" << "*.au" << "*.snd" << "*.aif" << "*.aiff" << "*.8svx" << "*.sph" << "*.sf" << "*.voc" << "*.w64"
                        << "*.cue"
                        << "*.mp1" << "*.mp2" << "*.mp3"
                        << "*.ay" << "*.gms" << "*.gym" << "*.hes" << "*.kss" << "*.nsf" << "*.nsfe" << "*.sap" << "*.spc" << "*.vgm" << "*.vgz)"
                        << "*.flac" << "*.oga"
                        << "*.ape"
                        << "*.aac"
                        << "*.mid"
                        << "*.sid" << "*.mus" << "*.str" << "*.prg" << "*.P00"
                        << "*.wma" << "*.ape" << "*.tta" << "*.m4a" << "*.ra" << "*.shn" << "*.vqf" << "*.ac3" << "*.tak" << "*.dsf" << "*.dsdiff" << "*.webm"
                        << "*.mod" << "*.s3m" << "*.xm" << "*.it" << "*.669" << "*.amf" << "*.ams" << "*.dbm" << "*.dmf" << "*.dsm" << "*.far" << "*.mdl" << "*.med" << "*.mtm" << "*.okt" << "*.ptm" << "*.stm" << "*.ult" << "*.umx" << "*.mt2" << "*.psm" << "*.mdz" << "*.s3z" << "*.xmz" << "*.itz" << "*.mdr" << "*.s3r" << "*.xmr" << "*.itr" << "*.dgz" << "*.s3gz" << "*.xmgz" << "*.itgz"
                        << "*.adl" << "*.hsc" << "*.ksm" << "*.lds" << "*.amd" << "*.d00" << "*.rad"
                        << "*.sap" << "*.cm3" << "*.cmc" << "*.cmr" << "*.cms" << "*.dmc" << "*.dlt" << "*.mpd" << "*.mpt" << "*.rmt" << "*.tm2" << "*.tm8" << "*.tmc"
                        << "*.vtx" << "*.asc" << "*.sqt" << "*.*psg" << "*.stc" << "*.stp" << "*.pt1" << "*.pt2" << "*.pt3" << "*.psc" << "*.ay"
                        << "*.dts" << "*.cpt"
                        << "*.fc" << "*.fc13" << "*.fc14" << "*.smod"
                        << "*.ahx" << "*.hvl"
                        << "*.ofr" << "*.ofs"
                        << "*.psf" << "*.spu" << "*.ssf" << "*.qsf" << "*.dsf" << "*.minipsf" << "*.minissf" << "*.miniqsf" << "*.minidsf"
                        << "*.sc68"
                        << "*.spx"
                        << "*.v2m"
                        << "*.ym"
                        << "*.zip";
}

QStringList MusicFormats::supportFormatsFilterDialogString()
{
    return QStringList()<< "All File(*.*)"
                        << "MusePack File(*.mpc)"
                        << "WavPack File(*.wv)"
                        << "Ogg Vorbis File(*.ogg)"
                        << "PCM File(*.wav *.au *.snd *.aif *.aiff *.8svx *.sph *.sf *.voc *.w64)"
                        << "CUE File(*.cue)"
                        << "MPEG File(*.mp1 *.mp2 *.mp3)"
                        << "Game File(*.ay *.gms *.gym *.hes *.kss *.nsf *.nsfe *.sap *.spc *.vgm *.vgz)"
                        << "FLAC File(*.flac *.oga)"
                        << "Monkey's Audio File(*.ape)"
                        << "Ogg Opus File(*.opus)"
                        << "ADTS AAC File(*.aac)"
                        << "MIDI File(*.mid)"
                        << "SID File(*.sid *.mus *.str *.prg *.P00)"
                        << "FFmpeg File(*.wma *.ape *.tta *.m4a *.ra *.shn *.vqf *.ac3 *.tak *.dsf *.dsdiff *.webm)"
                        << "ModPlug File(*.mod *.s3m *.xm *.it *.669 *.amf *.ams *.dbm *.dmf *.dsm *.far *.mdl *.med *.mtm *.okt *.ptm *.stm *.ult *.umx *.mt2 *.psm *.mdz *.s3z *.xmz *.itz *.mdr *.s3r *.xmr *.itr *.dgz *.s3gz *.xmgz *.itgz)"
                        << "AdLib Sound File(*.adl *.hsc *.ksm *.lds *.amd *.d00 *.rad)"
                        << "Another Slight Atari File(*.sap *.cm3 *.cmc *.cmr *.cms *.dmc *.dlt *.mpd *.mpt *.rmt *.tm2 *.tm8 *.tmc)"
                        << "AY/YM Audio File(*.vtx *.asc *.sqt *psg *.stc *.stp *.pt1 *.pt2 *.pt3 *.psc *.ay)"
                        << "DTS Coherent Acoustics File(*.dts *.cpt)"
                        << "Future Composer File(*.fc *.fc13 *.fc14 *.smod)"
                        << "HVL Module File(*.ahx *.hvl)"
                        << "OptimFrog File(*.ofr *.ofs)"
                        << "Audio Overload File(*.psf *.spu *.ssf *.qsf *.dsf *.minipsf *.minissf *.miniqsf *.minidsf)"
                        << "Atari ST(E) And Amiga File(*.sc68)"
                        << "Speex Audio File(*.spx)"
                        << "V2 Module Audio File(*.v2m)"
                        << "ST-Sound File(*.ym)"
                        << "Zip File(*.zip)";
}

QStringList MusicFormats::supportFormatsSpekString()
{
    return QStringList()<< "*.3gp *.aac *.aif *.aifc *.aiff *.amr *.awb *.ape *.au *.dts *.flac "
                           "*.flv *.gsm *.m4a *.m4p *.mp3 *.mp4 *.mp+ *.mpc *.mpp *.oga *.ogg *.opus *.ra "
                           "*.ram *.snd *.wav *.wma *.wv";
}

QStringList MusicFormats::supportFormatsPlaylistDialogString()
{
    return QStringList()<< "File(*.tkpl *.m3u *.m3u8 *.pls *.wpl *.xspf *.asx *.kwl *.kgl *.fpl *.csv *.txt)"
                        << "TTKlist File(*.tkpl)"
                        << "M3U File(*.m3u)"
                        << "M3U8 File(*.m3u8)"
                        << "Playlist File(*.pls)"
                        << "Windows Playlist File(*.wpl)"
                        << "XML Shareable Playlist File(*.xspf)"
                        << "Foobar2k Playlist File(*.fpl)"
                        << "Windows Media Playlist File(*.asx)"
                        << "KuWo Playlist File(*.kwl)"
                        << "KuGou Playlist File(*.kgl)"
                        << "CSV Playlist File(*.csv)"
                        << "TXT Playlist File(*.txt)";
}

QString MusicFormats::supportFormatsPlaylistString()
{
    return QString("TTKlist File(*.tkpl);; \
                    M3U File(*.m3u);; \
                    M3U8 File(*.m3u8);; \
                    Playlist File(*.pls);; \
                    Windows Playlist File(*.wpl);; \
                    XML Shareable Playlist File(*.xspf);; \
                    Windows Media Playlist File(*.asx);; \
                    CSV Playlist File(*.csv);; \
                    TXT Playlist File(*.txt);; \
                    Numbered Playlist File(*.nfn)");
}
