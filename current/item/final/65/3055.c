
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2146; }

// ���������촦��
void create()
{
        set_name("���ͷ��");
        set_picid_1(6580);
        set_picid_2(6580);

        set_level(55);
        set_value(8500);
        set_max_lasting(21899);
        set("ap", 0);
        set("dp", 100);
        set("cp", 0);
        set("pp", 33);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���ͷ��";
}
