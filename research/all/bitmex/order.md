order_id: Uuid
cl_ord_id: Option<String>
cl_ord_link_id: Option<String>
account: Option<i64>
symbol: Option<String>
side: Option<Side>
simple_order_qty: Option<f64>
order_qty: Option<i64>
price: Option<f64>
display_qty: Option<i64>
stop_px: Option<f64>
peg_offset_value: Option<f64>
peg_price_type: Option<PegPriceType>
currency: Option<String>
settl_currency: Option<String>
ord_type: Option<OrdType>
time_in_force: Option<TimeInForce>
exec_inst: Option<ExecInst>
contingency_type: Option<ContingencyType>
ex_destination: Option<String>
ord_status: Option<String>
triggered: Option<String>
working_indicator: Option<bool>
ord_rej_reason: Option<String>
simple_leaves_qty: Option<f64>
leaves_qty: Option<i64>
simple_cum_qty: Option<f64>
cum_qty: Option<i64>
avg_px: Option<f64>
multi_leg_reporting_type: Option<String>
text: Option<String>
transact_time: Option<DateTime<Utc>>
timestamp: Option<DateTime<Utc>>