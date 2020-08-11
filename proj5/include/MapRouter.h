#ifndef MAPROUTER_H 	  			 	 
#define MAPROUTER_H

#include <vector>
#include <istream>
#include<unordered_map>
#include<set>
class CMapRouter{
    public:
        using TNodeID = unsigned long;
        using TStopID = unsigned long;
        using TLocation = std::pair<double, double>;
        using TPathStep = std::pair<std::string, TNodeID>;
        
        static const TNodeID InvalidNodeID;
    private:
		using TNodeIndex = size_t;
		struct SEdge {
			double Distance;
			TNodeIndex OtherNode;
			double Maxspeed;
			double time;

		};
		struct SNode {
			TNodeID DNodeID;
			double DLatitude;
			double DLongitude;
			std::vector<SEdge> Edges;
		};
		struct pair_hash
		{
			template <class T1, class T2>
			std::size_t operator() (const std::pair<T1, T2>& pair) const
			{
				return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
			}
		};

		std::vector<SNode> DNodes; //a vector of the nodes
		std::vector<TNodeID> SortID; ///holds the ID of the Sorted Nodes
		std::vector<std::string> BusRoutes; //holds the names to the bus routes
		std::unordered_map<std::string, std::vector<TStopID>> Routesmap; //the map that matches the StopNodes to their names
		std::unordered_map<TStopID, TNodeID> StopRoutesmap;//maps the stopIDs with the NodeIDs
		std::unordered_map<TNodeID, TNodeIndex> DNodeIDToIndex; //maps the NodeID with the NodeIndex
		std::vector<TStopID> Stops; //holds the ID of the stop nodes
		std::vector<TNodeIndex> TempIndex;
		std::unordered_map<std::pair<TNodeIndex, TNodeIndex>, std::vector<std::string>, pair_hash > IndextoSet;
		std::unordered_map<std::pair<TNodeIndex, TNodeIndex>, std::vector<TNodeIndex>, pair_hash> PairsToPath;
		double Djikstra(TNodeIndex src, TNodeIndex dest, std::string EdgeType, std::vector<TNodeIndex> &indeces);
		std::string DegreeMinSec(double &latlon) const;
		std::string Bearing(double &bearing) const;
    public:
        CMapRouter();
        ~CMapRouter();
        static double HaversineDistance(double lat1, double lon1, double lat2, double lon2);
        static double CalculateBearing(double lat1, double lon1,double lat2, double lon2);
        bool LoadMapAndRoutes(std::istream &osm, std::istream &stops, std::istream &routes);
        size_t NodeCount() const;
        TNodeID GetSortedNodeIDByIndex(size_t index) const;
        TLocation GetSortedNodeLocationByIndex(size_t index) const;
        TLocation GetNodeLocationByID(TNodeID nodeid) const;
        TNodeID GetNodeIDByStopID(TStopID stopid) const;
        size_t RouteCount() const;
        std::string GetSortedRouteNameByIndex(size_t index) const;
        bool GetRouteStopsByRouteName(const std::string &route, std::vector< TStopID > &stops);
        
        double FindShortestPath(TNodeID src, TNodeID dest, std::vector< TNodeID > &path);
        double FindFastestPath(TNodeID src, TNodeID dest, std::vector< TPathStep > &path);
        bool GetPathDescription(const std::vector< TPathStep > &path, std::vector< std::string > &desc) const;
};

#endif
