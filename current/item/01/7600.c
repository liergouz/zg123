/*---------------------------------------------------------------------------------*\
	������Ʒ��ս�����䡣������ĵ���ս�������趨��
	�� cjxx �� 2007-09-04 ����
\*---------------------------------------------------------------------------------*/
inherit ITEM;
#define ZG_DICTIONARY		"/quest/zg_dict"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}

//	�����Ƿ����
int is_usable() {
	return 1;
}
//	���캯��
void create() {
	set_name("ս������");
	set_picid_1(1017);
	set_picid_2(1017);	
	set_value(0);		//	��ֵΪ0
	//set_no_get(1);	//	���ɴ浱��
	set_no_give(1);		//	���ɸ���
	set_no_sell(1);		//	���ɳ���
}
//	��������
string get_desc() {
	return "�ഫ�����ϼ�����ÿ����ε���ҿ���ȥð�յĵط���\n���ÿ����һ��������һ��ҡ���Ļ��ᣬ�������������ס��λ��ᣬ�ͻ���ʧ����";
}
//	ִ��ʹ��Ч������
int get_use_effect(object me) {
	return __FILE__->get_use_effect_callout(me,this_object());
}
//	ʵ��ʹ��Ч������
int get_use_effect_callout(object me,object item) {
	ZG_DICTIONARY->search_in_user(me);
}