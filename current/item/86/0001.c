
// �Զ����ɣ�/make/equip/86b

inherit NECK;

// ���������촦��
void create()
{
        set_name("��ѧ������");
        set_picid_1(8600);
        set_picid_2(8600);
        set_unit("��");

        set_level(5);
        set_value(1);
        set_max_lasting(1899);
        set("cp%", 2);
        set("pp", 10);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ѧ������";
}
