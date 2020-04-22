// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2019 The CryptoVerification developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x00000480e4b9a17298cf2e7257b31c666f40009071b4f7b60485a3eec54ffa30"))
	(1, uint256("0x00000c0aafd20dc4f7705abc5f4b1b49f0160f9a382a4247138ea9493d1c763a"))
	(221, uint256("0x000005157d40f4d0ac3b5b310b1bb7b10263c15e1354fbb755b44a0b2b656e60"))
	(872, uint256("0xded6edae10a4f4563c1d1ddac00eddf781dc8b959029ce72683f6e59c6d482cf"))
	(1505, uint256("0x9c9cc465ad877097be91d62212f6fbdce716fb9e1f4310b8e87a0741ab6df8c4"))
	(1987, uint256("0x400472d0f592b7c147e70cda56680424e58081d15d31f7a7814ba6a6e5d272c0"))
	(2841, uint256("0x3977e7002e3e73f49dbaf78e76c4206bfb2ed08f89685f7cc734431c24241f24"))
	(11702, uint256("0xb9b5807c5941b7bafbdc7165a7ab5d311052fb55aa4f0d3e2f7b74262ffb2b72"))
	(26898, uint256("0x3ccd30bf84fc830ff1350f5b6554f43ff28cf6771d6667c93a3ce89eb7d51213"))
	(37154, uint256("0x657839594c0f35ae3819b1a5dc87a997f56ac4f6fbeef1c47566db57c956587f"))
	(49214, uint256("0xac4a8d06c4d74dd946d056d2efac63c7b2d00c1bbcdcdac3324de6f036303b88"))
	(54729, uint256("0xde2aecc884c51ab963b20660ad9124133e680b8a00c1e12bcd2ff0a2999dce05"))
	(61026, uint256("0x849786f19903c6b6a4f44e1785c9cc5ea4a0f16c69707603b113883bc8909585"))
	(78721, uint256("0x261628910ca70ed78464133b22f3eedf291eb1c301c2518fc246779cc3c3ca31"))
	(80011, uint256("0x2f6055c4613152faa253c5c520c9fcbee3b6c8462b2332a635af6af2bf8b5c02"))
	(87469, uint256("0x4d999dbbdfe6bdb5867e91ca68052f8ddfa3c576ea7dd7c1c10eaa2663373c99"))
	(94801, uint256("0x9ec1a7f42d2f214e7bfe5206b51ec297a99c085e384e9a5c3b2501d32db51532"))
	(105894, uint256("0x92bba2250cd6ef00e9d9ee129b70eb1fac1b8601099da75d54db409c4b998185"))
	(118728, uint256("0x6cd037aeaa04dd3cdae6309a47acfc7df2f9bc5c958096594fe4454dbadf480c"))
	(131109, uint256("0x19ba059c18fe42423f05c392bc743d1e703de8e1ba490628970c3e280ecf8160"))
	(136584, uint256("0x64173e8cab01151e3920c4e23b646716c2c1a32eb756f333e5e3f6aa65c16865"))
	(141159, uint256("0x28ee45a02eba21982cacd7522c729e25c94cda58c6de1d71c09fa847c22d4468"))
	(151011, uint256("0x5cd691ce4bd6e7bbb7312ee2a25beb3c1cf233e103d7d260fc289228bb30fd00"))
	(178159, uint256("0x4337f4c88cd4d6d31bf8f7b6dc8f682e4da98af7d1d542d5199d20eee10d9e06"))
	(211576, uint256("0x0d6c548aaba15aeca45a692970eb7fc7c114af784e008d565d9e5efab1ed7641"))
	(238103, uint256("0x9aed3cd615ff13d809baaaf6718f307f8a52fdc20699d7651155f4982703aa8b"))
	(271829, uint256("0x359045af877bd8e56d36cac6f75bf6aa0d97e0e15f1a4e0815ef5c7426ca2e3c"))
	(291156, uint256("0xaba104ab6794e9e0637d8f22152322c46400165c678dee688c1e0f29f4ae8922"))
	(291157, uint256("0x626f59f22987c6e0779cc560d601a729e72ee032a5f28660dd96ebe312b44882"))
	(291158, uint256("0x1d8249668f81559de4b07a23217ed1bfd21bfab3c4218ef58706e28326a2d463"))
	(293894, uint256("0xcfebfb7cf45bb468afe311c816309b2250e072ab3ee2cd50a6af2a774dcf0816"))
	(351482, uint256("0x0eeec0e1263606e91f2e3df9131bdf1a8771927078a80515a4b424d9185f509d"))
	(408133, uint256("0x04964a9f2633896ba82d937089a91400cc4035b7b5514dcb84e38e760fb83a75"))
	(412511, uint256("0xa7c9016336a79d4d5536af7f48d70681c3df36757daff8a05ffeed7b30caa378"))
	(443205, uint256("0x1b3da6c3e6ebbd5f16a431eca4b159e6d8212cc5e8dc1865a62bd8798cc2ad3a"))
;
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
	1587532120, // * UNIX timestamp of last checkpoint block
    889159,		// * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1560225600,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xf1;
        pchMessageStart[1] = 0x9c;
        pchMessageStart[2] = 0xda;
        pchMessageStart[3] = 0x4e;
        vAlertPubKey = ParseHex("0000098a3ba6ba6e7423fa5cbd6a89e0a9a5248f88d332b14a5cb1a8b7ed2c1eaa335fc8dc4f012cb8241cc0bdafd6ca70c5f5448916e4e6f511bcd746ed57dc50");
        nDefaultPort = 1316;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // CryptoVerification starting difficulty is 1 / 2^12
        //nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // CVCC: 1 day
        nTargetSpacing = 1 * 60;  // CVCC: 1 minute
        nMaturity = 61;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 36000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 225;
        nModifierUpdateBlock = 999999999;
        nZerocoinStartHeight = 9999999;
        nZerocoinStartTime = 2081097200;
        nBlockEnforceSerialRange = 253; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = ~1; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = ~1; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = ~1; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0 * COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 9999999; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nEnforceNewSporkKey = 1560315600; //!> Sporks signed after (GMT):  Wednesday, June 12, 2019 5:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1560394800; //!> Fully reject old spork key after (GMT): Thursday, June 13, 2019 3:00:00 AM

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "CryptoVerification Coin.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
		txNew.vout[0].SetEmpty();
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04b10e83b2703ccf321f7dbd62dd5845ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9a4b77b26d92428c61256cd42774babea0a073b2ed0c9") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1560225600;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1376644;


        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000480e4b9a17298cf2e7257b31c666f40009071b4f7b60485a3eec54ffa30"));
        assert(genesis.hashMerkleRoot == uint256("0x052cc0ad31f0b1de70f13d92f505eb195dc15a7bf1e8a07f643f13b6d37d76bf"));

        vSeeds.push_back(CDNSSeedData("0", "149.248.62.208"));
		vSeeds.push_back(CDNSSeedData("1", "2001:19f0:b001:44f:5400:02ff:fe1b:dd0f"));
		vSeeds.push_back(CDNSSeedData("2", "78.141.199.188"));
		vSeeds.push_back(CDNSSeedData("3", "2001:19f0:7402:19fd:5400:02ff:fe1b:d980"));
		vSeeds.push_back(CDNSSeedData("4", "78.141.204.73"));
		vSeeds.push_back(CDNSSeedData("5", "2001:19f0:7401:8d7b:5400:02ff:fe1b:d981"));
		vSeeds.push_back(CDNSSeedData("6", "95.179.195.211"));
		vSeeds.push_back(CDNSSeedData("7", "2001:19f0:7402:c10:5400:02ff:fe1b:d982"));
		vSeeds.push_back(CDNSSeedData("8", "95.179.196.231"));
		vSeeds.push_back(CDNSSeedData("9", "2001:19f0:7402:1153:5400:02ff:fe1b:d983"));
		vSeeds.push_back(CDNSSeedData("10", "217.163.11.82"));
		vSeeds.push_back(CDNSSeedData("11", "2001:19f0:7401:8616:5400:02ff:fe1b:d984"));
		vSeeds.push_back(CDNSSeedData("12", "45.63.97.36"));
		vSeeds.push_back(CDNSSeedData("13", "2001:19f0:7402:1d31:5400:02ff:fe1b:d985"));
		vSeeds.push_back(CDNSSeedData("14", "78.141.198.73"));
		vSeeds.push_back(CDNSSeedData("15", "2001:19f0:7402:14fd:5400:02ff:fe1b:d986"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 28);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04791ea72907e595e4f55ac6cd2d6662e36b2ff4f212adb85034c6af04d19b75ed4b9ae640c70c7a14f024baf774d61f294330b6b612240f3f3d86c63f223ee31a";
        strSporkKeyOld = "04791ea72907e595e4f55ac6cd2d6662e36b2ff4f212adb85034c6af04d19b75ed4b9ae640c70c7a14f024baf774d61f294330b6b612240f3f3d86c63f223ee31a";
        strObfuscationPoolDummyAddress = "CRw1YnjGGy75CPEELoRdHfUqhvMPWTwPNL";
        nStartMasternodePayments = 1560326400; // Wednesday, June 12, 2019 8:00:00 AM GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zcvcc to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("000010e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9");
        nDefaultPort = 51474;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // CryptoVerification: 1 day
        nTargetSpacing = 1 * 60;  // CryptoVerification: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        nZerocoinStartTime = 1501776000;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 9891737; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 9891730; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 444020; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1560225600;
        genesis.nNonce = 2402015;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "cryptoverification-testnet.seed.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "cryptoverification-testnet.seed2.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("s3v3nh4cks.ddns.net", "s3v3nh4cks.ddns.net"));
        vSeeds.push_back(CDNSSeedData("88.198.192.110", "88.198.192.110"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet cryptoverification addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet cryptoverification script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet cryptoverification BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet cryptoverification BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet cryptoverification BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04A8B319388C0F8588D238B9941DC26B26D3F9465266B368A051C5C100F79306A557780101FE2192FE170D7E6DEFDCBEE4C8D533396389C0DAFFDBC842B002243C";
        strSporkKeyOld = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        //nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // CryptoVerification: 1 day
        nTargetSpacing = 1 * 60;        // CryptoVerification: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1560225600;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    //virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
