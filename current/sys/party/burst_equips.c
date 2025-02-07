/*------------------------------------------------------------------------------------------*\
	�����װ�Ļ�����ļ�
	07-06-26 	�� Cjxx ����
	07-06-27  18:46 �������ʱ����ƿ��
	07-06-28  18:00 ���ʱ����Ѱ���ƿ�ܣ��޸�֮ǰһ������BUG��
\*------------------------------------------------------------------------------------------*/
#include <ansi.h>
#include <time.h>
#include <public.h>
inherit SAVE_F;


#define _DEBUG(str) 		  ;//if(objectp(find_char("1"))) tell_user(find_char("1"),str);

#define BZ_WEEK 		  "week"		//	������Ѱ��־
#define BZ_MONTH		  "month"		//	�·���Ѱ��־
#define BZ_DAY			  "day"			//	������Ѱ��־
#define BZ_HOUR			  "hour"		//	Сʱ��Ѱ��־

private string active_name	= "�����װ";		//	�����
private string cycle_way	= "week";		//	���ѵ���� BZ_WEEK / BZ_MONTH / BZ_DAY / BZ_HOUR

private int BZ_ACTIVE_BEFORE1	= 5;			//	���ʼǰ�ĵ�һ��ʱ��㣨�֣�
private int BZ_ACTIVE_BEFORE2	= 50;			//	���ʼʱ�ĵڶ���ʱ��㣨�֣�--�����ݲ�֧�ֶԴ�ʱ���Ŀ���
private int BZ_TIME_CACHE	= 1;			//	�ٽ�ʱ�仺�� -- �ɺ��Ե�ʱ�������

private int active_from		= 51700;		//	���ʼʱ�� [0-6]/[1-31][0-23][0-59] -- ���ݻ����Ѳģʽ
private int active_to		= 51800;		//	�����ʱ�� [0-6]/[1-31][0-23][0-59]

private int if_active		= 0;			//	��Ƿ�ʼ�ı�־
private int if_active_next	= 1;			//	�Ƿ��Զ�������һ�εı�־
private int if_step_near_time	= 0;			//	���ʼǰ���ٽ�ʱ���Ƿ���е����Ӽ�ʱ

private int time_clip(int time_int, int mins); 		//	ʱ�����������
private int time_add( int time_int, int mins);		//	ʱ�����������
private int have_mins(int time_int);			//	ȡ�õ�ǰ����ʱ����ӵ�еķ�����
private int get_time(string way);			//	��ȡһ��ϵͳ�Ͽɵ�����ʱ���
private int in_time_area(int time_int, int time_from, int time_to);	//	�ж�ĳʱ����Ƿ���һ��ʱ�����
private int count_during_time(int time_from, int time_to);		//	���㵽��һ��ʱ����������Ҫ�ķ�����


//	��װ���ر�������
private static object *lao_renzha=({});
private static mixed renzha_position= ({
	({010,150,203,}),
	({020,170,168,}),
	({030,142,127,}),
	({040,223,73 ,}),
	({050,239,133,}),
	({060,113,167,}),
	({070,289,183,}),	
});

void turn_off_activity();
void turn_on_activity();

void do_activity();					//	�����ִ�еĺ���
void on_active_before(int callout_delay_time);		//	���ʼʱִ�еĺ���
void on_active_near(int callout_delay_time);		//	��ٽ�ʱִ�еĺ���
void on_active_playing(int callout_delay_time);		//	���ʼʱִ�еĺ���
void on_active_finish(int callout_delay_time);		//	��ոս���ʱִ�еĺ���

void SAVE_BINARY() {}

string get_save_file()	{ 
	return "data/baozhuang"SAVE_EXTENSION;
}

//	���캯��
void create() {
	restore();
}

//	�趨��Ŀ�ʼ�ͽ���ʱ�� -- ����ʼʱ����ڽ���ʱ��ʱ��Ϊ��ʱ�������Ĳ���
void set_active_time(int from, int to) {
	int tmp_active_on = if_active;
	active_from = (cycle_way == BZ_WEEK && from > 70000) ? from - 70000 : from;
	active_to   = (cycle_way == BZ_WEEK && to   > 70000) ? to   - 70000 : to;
	turn_off_activity();
	if(tmp_active_on) {
		turn_on_activity();
	}
	_DEBUG(sprintf("����ʱ�� %d <--> %d",active_from,active_to));
	save();
}

//	ȡ�û��ʼ����ʱ���� ��-�� �ָ
string get_active_time() {
	return sprintf("%d-%d",active_from,active_to);
}

//	��������ģʽ
void set_cycle_way(string way) {
	cycle_way = way == BZ_WEEK ? way : way == BZ_MONTH ? way : way == BZ_DAY ? way : BZ_HOUR;
	save();
	_DEBUG(sprintf("������ת����Ϊ %s",cycle_way));	
}

// 	���û�ٽ�ʱ���1
void set_active_before1(int mins) {
	BZ_ACTIVE_BEFORE1 = mins;
	save();
}

//	����ʱ���ٽ绺��
void set_time_cache(int mins) {
	BZ_TIME_CACHE = mins;
	save();
}

//	�����
void turn_on_activity() {	
	turn_off_activity();
	_DEBUG("DEBUG -- �����");
	if_active = 1;
	do_activity();
	save();
}

//	�رջ
void turn_off_activity() {
	_DEBUG("DEBUG -- �رջ");
	if_active = 0;
	on_active_finish(0);
	do_activity();
	save();
}

//	�ѵ�ǰʱ�����ʾΪһ����ʶ���ʱ���ִ�
string show_time_stamp(int time_stamp) {
	mixed *time_box = localtime(time_stamp);
	return sprintf("%04d-%02d-%02d %02d:%02d:%02d",time_box[TIME_YEAR],time_box[TIME_MON]+1,time_box[TIME_MDAY],time_box[TIME_HOUR],time_box[TIME_MIN],time_box[TIME_SEC]);
}

//	���л -- ����ʱ�����������������Ŀ��ƺ�����
void do_activity() {	
	string func_name = "do_activity";
	int now_time ,callout_delay_time;
	if(!if_active) {
		remove_call_out(func_name);
		return;
	}
	now_time = get_time(cycle_way);
	if(in_time_area(now_time,time_clip(active_from,BZ_ACTIVE_BEFORE1),active_from)) {
		callout_delay_time = count_during_time(now_time,active_from);
		on_active_near(callout_delay_time);		//	�ǰ������
		call_out(func_name,if_step_near_time ? 60 : callout_delay_time*60);
		return;		
	} else if(in_time_area(now_time,time_clip(active_from,BZ_TIME_CACHE),active_to)) {
		callout_delay_time = count_during_time(now_time,time_add(active_to,BZ_TIME_CACHE));
		on_active_playing(callout_delay_time);		//	���
		call_out(func_name,callout_delay_time*60);
		return;		
	} else if(in_time_area(now_time,time_clip(active_to,BZ_TIME_CACHE?BZ_TIME_CACHE:1),time_add(active_to,BZ_TIME_CACHE+2))) {
		on_active_finish(0);				//	��ոս���
		if(!if_active_next) {
			remove_call_out(func_name);
			return;
		}
	}
	callout_delay_time = count_during_time(now_time,time_clip(active_from,BZ_ACTIVE_BEFORE1));
	on_active_before(callout_delay_time);			//	�֮�� ��֮�� / ֮ǰ��
	call_out(func_name,callout_delay_time*60);
	_DEBUG(sprintf("�´λص�ʱ���� %s",show_time_stamp(time()+callout_delay_time*60)));
}

//	���ʼʱִ�еĺ���
void on_active_before(int callout_delay_time) {
	_DEBUG(sprintf("DEBUG--Ŀǰ���û�п�ʼ���ٴε��û�����ڣ�%d�����Ӻ�",callout_delay_time));
}
//	��ٽ�ʱִ�еĺ���
void on_active_near(int callout_delay_time) {
	_DEBUG(sprintf("DEBUG-- �����ǻǰ�ļ�����״̬�����ʽ��ʼ�ڣ�%d�����Ӻ�",callout_delay_time));
	USER_D->user_channel(sprintf("%d���Ӻ󳬷������%s�������ʼ��Ϊ�˵õ����õ�װ�����尡��",callout_delay_time,active_name));	
}

//	����NPC��һ������
void set_npc_status(object npc,int level,int *skills,int *other_stat) {
	int i,size;
	for(i=0,size=sizeof(skills);i<size;i++) {	//	���ü���
		npc->set_skill(skills[i],level);
	}
	if(other_stat[0]) {				//	0 �����н��ٶ�
		npc->set_walk_speed(other_stat[0]);
	}
	if(other_stat[1]) {				//	1 ���ù����ٶ�
		npc->set_attack_speed(other_stat[1]);
	}
	if(other_stat[2]) {				//	2 �����������
		npc->add_dp(npc->get_dp()*other_stat[2]/100);
	}
	if(other_stat[3]) {				//	3 ����Ѫ����
		npc->add_max_hp(npc->get_max_hp()*other_stat[3]/100);
	}
	if(other_stat[4]) {				//	4 ���Ӷ���
		npc->add_sp(npc->get_sp()*other_stat[4]/100);
	}
	if(other_stat[5]) {				//	5 ����������			
		npc->add_ap(npc->get_ap()*other_stat[5]/100);		
	}
	if(other_stat[6]) {				//	6 ���ӷ�����
		npc->add_mp(npc->get_mp()*other_stat[6]/100);
	}
	if(other_stat[7]) {				//	7 ���ӷ���
		npc->add_pp(npc->get_pp()*other_stat[7]/100);
	}
	if(other_stat[8]) {				//	8 ���ӷ���������
		npc->add_cp(npc->get_cp()*other_stat[8]/100);
	}
	if(other_stat[9]) {				//	9 �趨��������
		npc->set("robber.type",other_stat[9]);	
	}
}
//	���ʼʱִ�еĺ��� -- ����д���ڱ�װ�������
void on_active_playing(int callout_delay_time) {
	int x,y,z,i,count,burst_point,rand_int,level;
	object map,renzha;
	level = 80;
	_DEBUG(sprintf("DEBUG--Ŀǰ����ڽ����У��ٴε��û�����ڣ�%d�����Ӻ�",callout_delay_time));
	USER_D->user_channel(sprintf("%s��Ѿ���ʼ�ˣ�Ϊ�˵õ����õ�װ��������ȥ�߹����������������ɣ�",active_name));
	for(i=0,count=1;i<100;i++) {
		burst_point = XY_D->get_city_point(count,IS_CHAR_BLOCK);
		if(!burst_point) {
			_DEBUG("DEBUG -- ��ͼ����û�г�ʼ���ɹ�");
			continue;
		}
		renzha = new("npc/boss/9962_laorenzha");
		if(!objectp(renzha)) {
			_DEBUG("DEBUG--������û�����ɳɹ�");
			continue;
		}
		NPC_ENERGY_D->init_level(renzha,level);	//	������һ�����һ�µȼ�
		renzha->set_max_seek(8);
		rand_int = random(100);			//	100 ����ȥ��һЩͨ������
		_DEBUG(sprintf("���������%d",rand_int));
		if(rand_int < 20) {			//	���������
			set_npc_status(renzha,level,({3483,2512,2416}),({3,10,-30,60000,1100,10,50,0,0,1}));
		} else if(rand_int < 40 ) {		//	������ͷ���
			set_npc_status(renzha,level,({2216,2313,2314}),({3,10,300,60000,0,20,50,-40,0,2}));
		} else if(rand_int < 60 ) {		//	�߷��������
			set_npc_status(renzha,level,({4251,4231,4232,4234,4243}),({4,10,-30,60000,0,0,600,80,20,3}));
		} else if(rand_int < 70 ) {		//	��Ѫ
			set_npc_status(renzha,level,({3173,2118,2114,2115}),({3,10,-30,75000,0,30,30,-30,0,4}));
		} else if(rand_int < 90 ) {		//	��Ѫ������߷���
			set_npc_status(renzha,level,({3632,2616,2615}),({3,10,35,60000,300,50,100,100,0,5}));
		} else {				//	ǿ�����ٻ�
			renzha->set_char_picid(8013);
			set_npc_status(renzha,level,({4143,4144,4145}),({3,8,45,60000,300,0,150,45,0,6}));
		}
		z =  burst_point / 1000000;	
		x = (burst_point % 1000000) / 1000;
		y =  burst_point % 1000;
		//_DEBUG(sprintf("DEBUG--(Z-%03d X-%03d Y-%03d)",z,x,y));
		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) {
			_DEBUG("DEBUG-- ��ͼ����û�гɹ�");
			continue;
		}
		//	���뵽��Ӧ�ĳ����м�ȥ
		//	07-07-16 P12:26 �޸�Ϊ��������
		renzha->add_to_scene(renzha_position[count-1][0],renzha_position[count-1][1],renzha_position[count-1][2],3);
		_DEBUG(sprintf("DEBUG--(Z-%03d X-%03d Y-%03d)",renzha_position[count-1][0],renzha_position[count-1][1],renzha_position[count-1][2]));
		//renzha->add_to_scene(z,x,y,3);
		map->add_reset(renzha);
		//	����ָ�뵽һ��������
		lao_renzha += ({renzha});		
		if(++count > 7 ) {
			break;
		}
	}
}
//	��ոս���ʱִ�еĺ���
void on_active_finish(int callout_delay_time) {
	int i , size;
	_DEBUG(sprintf("DEBUG--Ŀǰ��ոս������ٴε��û�����ڣ�%d�����Ӻ�",callout_delay_time));
	//	����� -- ��������������ʧ״̬ -- NPC �ڲ�Ҳ�������Ӧ��������������������˫����
	for(i=0,size=sizeof(lao_renzha);i<size;i++) {
		if(objectp(lao_renzha[i]) && !objectp(lao_renzha[i]->get_enemy())) {
			lao_renzha[i]->remove_from_scene();
			destruct(lao_renzha[i]);
		}
	}
	lao_renzha = ({});
}

//	ȡ�õ�ǰ����ʱ����ӵ�еķ�����
private int have_mins(int time_int) {
	return ((time_int/10000)*24*60) + ((time_int % 10000)/100)*60 + (time_int % 100);
}
//	ȡ�õ�ǰָ��ģʽ��ʱ������ -- week / month / day / hour Ĭ��Ϊ week
private int get_time(string way) {
	mixed *now_box = localtime(time());
	switch(way) {
		default:
		case BZ_WEEK : return now_box[TIME_WDAY]*10000 + now_box[TIME_HOUR]*100 + now_box[TIME_MIN];
		case BZ_MONTH: return now_box[TIME_MDAY]*10000 + now_box[TIME_HOUR]*100 + now_box[TIME_MIN];
		case BZ_DAY  : return now_box[TIME_HOUR]*100 + now_box[TIME_MIN];
		case BZ_HOUR : return now_box[TIME_MIN];
	}
}
//	ָ��ʱ��Ŀ��ƺ��� -- ��������ԭ��һ�������ڵ�ʱ������������������������ȡ��һ������
private int time_cont(int h_mins) {
	switch(cycle_way) {
		default:
		case BZ_WEEK : h_mins = h_mins % (7*24*60);	break;
		case BZ_MONTH: h_mins = h_mins % (32*24*60) +1;	break;
		case BZ_DAY  : h_mins = h_mins % (24*60);	break;
		case BZ_HOUR : h_mins = h_mins % (60);		break;
	}
	return (h_mins/(24*60))*10000 + ((h_mins % (24*60)) / 60)*100 + ((h_mins % (24*60)) % 60);
}
//	����һ�����ʱ��Ĳ�ֵ
private int count_during_time(int time_from, int time_to) {
	if(time_from <= time_to) {
		return have_mins(time_clip(time_to,have_mins(time_from)));
	} else {
		switch(cycle_way) {
			default:
			case BZ_WEEK : return (7*24*60) - (have_mins(time_from) - have_mins(time_to));
			case BZ_MONTH: return (31*24*60)- (have_mins(time_from) - have_mins(time_to));
			case BZ_DAY  : return (24*60)   - (have_mins(time_from) - have_mins(time_to));
			case BZ_HOUR : return (60)      - (have_mins(time_from) - have_mins(time_to));
		}
	}
}
//	ָ��ʱ�������ļ����� -- ������������������ڵķ�Χ����Ѱ����һ�����ڵ�ʱ��ֵ
private int time_clip(int time_int, int mins) {
	return time_cont(have_mins(time_int)-mins);	
}
//	ָ��ʱ�������ļӲ��� -- ������������������ڵķ�Χ����Ѱ����һ�����ڵ�ʱ��ֵ
private int time_add(int time_int, int mins) {
	return time_cont(have_mins(time_int)+mins);
}
//	�жϸ�����ʱ��������Ƿ����ض�ʱ����� ���򷵻� 1 ���򷵻� 0 
private int in_time_area(int time_int, int time_from, int time_to) {
	int l = time_int < time_from ? 0 : 1;
	int r = time_int >= time_to  ? 0 : 1;
	return time_from < time_to ? l&r : l|r;
}