
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2234; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6625);
        set_picid_2(6625);

        set_level(95);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 176);
        set("cp", 0);
        set("pp", 67);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
