
// �Զ����ɣ�/make/equip/86b

inherit NECK;
int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8608);
        set_picid_2(8608);
        set_unit("��");

        set_level(0);
        set_value(80);
        set_max_lasting(2599);
//        set("cp%", 5);
        set("ap", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
