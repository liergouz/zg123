
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("ͭ��ʯ");
        set_picid_1(4905);
        set_picid_2(4905);
        set_unit("��");
        set_value(100);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���зḻ��ͭԪ�صĿ�ʯ"; 
}
