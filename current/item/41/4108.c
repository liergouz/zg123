
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("ħ��ʯ");
        set_picid_1(8913);
        set_picid_2(8913);
        set_unit("��");
        set_value(400);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ�������ž޴�������ʯ��"; 
}
