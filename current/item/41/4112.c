
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("����ʯ");
        set_picid_1(9913);
        set_picid_2(9913);
        set_unit("��");
        set_value(1000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���зḻ����Ԫ�صĿ�ʯ"; 
}
