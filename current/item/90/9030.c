
// �Զ����ɣ�/make/item/make90

inherit ITEM;
inherit COMBINED;

// ��������������
int get_max_combined() { return 5; }

// ��������ҩʶ��
int is_herb() { return 1; }

// ���������촦��
void create()
{
        set_name("��Ƥ");
        set_picid_1(9030);
        set_picid_2(9030);
        set_unit("��");
        set_value(150);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�в�ҩ��һ��";
}
