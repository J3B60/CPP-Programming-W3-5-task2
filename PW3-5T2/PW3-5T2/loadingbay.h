#define LOADINGBAY_h
class LoadingBay : public CargoStorage{
	public:
		void Arrive();
		void Leave();
	protected:
		vector<Pallet> LoadingBay_Storage;
}