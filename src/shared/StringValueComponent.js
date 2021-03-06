import { Component } from 'substance'

export default
class StringValueComponent extends Component {
  render($$) {
    let value = this.props.value
    let el = $$('div').addClass('sc-string-value')
    el.append(
      "'",
      value.data,
      "'"
    )
    return el
  }
}
